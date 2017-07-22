{ stdenv, lib, alsaLib, mesa, xorg, nodejs-slim, kore}:

stdenv.mkDerivation rec {
  name = "libKoreC";
  src = ./.;

  # LIB=-static-libgcc -static-libstdc++ -pthread -lasound -ldl -lGL -lX11 -lXinerama
  nativeBuildInputs = [
    alsaLib
    mesa
    xorg.libX11
    xorg.libXinerama
    nodejs-slim
    kore
  ];

  postUnpack = ''
    cd ./KoreC/
    mkdir Kore

    # Copy in the Kore framework
    cp -r ${kore}/* ./Kore

    # Generate the Kore project files based on the source's koremake file
    node Kore/make.js

    # Remove main(int, char**) and kore(int, char**) from the Linux backend
    cd ./Kore/Backends/System/Linux/Sources/Kore/
    chmod +w System.cpp
    substituteInPlace System.cpp \
      --replace "extern int kore(int argc, char** argv);" "" \
      --replace "int main(int argc, char** argv) {
	kore(argc, argv);
}" ""
    cd ../../../../../../

    # Patch the generated makefile to compile with -fpic and -shared, etc.
    cd ./build/Release/
    substituteInPlace makefile \
      --replace " -c " " -fpic -c " \
      --replace "-o \"KoreC\"" "-shared -o libkorec.so" \
      --replace "-o cwrapper.o" "-o cwrapper.o -std=c++11"
    cd ../../../
  '';

  buildPhase = ''
    make -C ./build/Release
  '';

  installPhase = ''
    # Copy the shared library to $out/lib
    mkdir -p $out/lib
    cp ./build/Release/libkorec.so $out/lib
  '';

  meta = with stdenv.lib; {
    description = "Shared library wrapping Kode's Kore framework";
    homepage = https://github.com/patternspandemic/KoreC;
    downloadPage = https://github.com/patternspandemic/KoreC;
    license = licenses.zlib;
    maintainers = [ maintainers.patternspandemic ];
    platforms = [ "x86_64-linux" ];
  };
}
