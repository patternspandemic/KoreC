{ stdenv, lib, alsaLib, mesa, xlibs, xorg, kore}:

stdenv.mkDerivation rec {
  name = "libKoreC";
  src = ./.;

  # May not need all these, or only subset?
  buildInputs = [alsaLib mesa xlibs xorg];

  sourceRoot = "./Sources";

  installPhase = ''
    mkdir -p $out/lib
    mkdir -p $out/include
  '';

  # postFixup = lib.optionalString (stdenv.system == "i686-linux" || stdenv.system == "x86_64-linux") ''
  #   substituteInPlace $out/resources/app/extensions/kha/Kha/Tools/khamake/node_modules/fs-extra/lib/copy-sync/copy-file-sync.js --replace "stat.mode" "33188"
  #   substituteInPlace $out/resources/app/extensions/kha/Kha/Kore/Tools/koremake/node_modules/fs-extra/lib/copy-sync/copy-file-sync.js --replace "stat.mode" "33188"
  # '';

  meta = with stdenv.lib; {
    description = "Shared library wrapping Kode's Kore framework";
    homepage = https://github.com/patternspandemic/KoreC;
    downloadPage = https://github.com/patternspandemic/KoreC;
    license = licenses.zlib;
    maintainers = [ maintainers.patternspandemic ];
    platforms = [ "x86_64-linux" ];
  };
}
