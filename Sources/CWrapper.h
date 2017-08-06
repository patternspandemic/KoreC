#include <Kore/pch.h>

/**** Kore namespaced types ****/

typedef unsigned char u8;   // 1 Byte
typedef unsigned short u16; // 2 Byte
typedef unsigned int u32; // 4 Byte
#ifdef KORE_WINDOWS
	typedef unsigned __int64 u64; // 8 Byte
#else
	typedef unsigned long long u64;
#endif
typedef char s8;   // 1 Byte
typedef short s16; // 2 Byte
typedef int s32; // 4 Byte
#ifdef KORE_WINDOWS
	typedef __int64 s64; // 8 Byte
#else
	typedef long long s64;
#endif
typedef u32 uint; // 4 Byte
typedef s32 sint; // 4 Byte
#ifdef KORE_64
	typedef s64 spint;
	typedef u64 upint;
#else
	typedef s32 spint;
	typedef u32 upint;
#endif

#ifdef __cplusplus
extern "C" {
#endif





/**** Window ****/

// Kore::RendererOptions
struct WS_Kore_RendererOptions;
typedef struct WS_Kore_RendererOptions {
	int textureFormat;
	int depthBufferBits;
	int stencilBufferBits;
	int antialiasing;
} WS_Kore_RendererOptions;

void Kore_RendererOptions_default(WS_Kore_RendererOptions* ro);

// Kore::WindowMode
typedef enum WE_Kore_WindowMode {
	WE_WindowModeWindow = 0,
	WE_WindowModeBorderless = 1,
	WE_WindowModeFullscreen = 2,
} WE_Kore_WindowMode;

// Kore::WindowOptions
struct WS_Kore_WindowOptions;
typedef struct WS_Kore_WindowOptions {
	const char* title;
	int width;
	int height;
	int x;
	int y;
	int targetDisplay;
	bool vSync;
	bool resizable;
	bool maximizable;
	bool minimizable;
	WE_Kore_WindowMode mode;
	bool showWindow;
	WS_Kore_RendererOptions rendererOptions;
} WS_Kore_WindowOptions;

void Kore_WindowOptions_default(WS_Kore_WindowOptions* wo);

/****************/





/**** System ****/

typedef unsigned long long ticks;

// Kore::Orientation
typedef enum WE_Kore_Orientation {
	WE_OrientationLandscapeLeft = 0,
	WE_OrientationLandscapeRight = 1,
	WE_OrientationPortrait = 2,
	WE_OrientationPortraitUpsideDown = 3,
	WE_OrientationUnknown = 4,
} WE_Kore_Orientation;

void Kore_System_init(const char* name, int width, int height);

int Kore_System_currentDevice();

int Kore_System_initWindow(WS_Kore_WindowOptions* options);
void Kore_System_destroyWindow(int id);
void* Kore_System_windowHandle(int windowId);
int Kore_System_windowWidth(int id);
int Kore_System_windowHeight(int id);
int Kore_System_windowCount();

int Kore_System_screenDpi();

void Kore_System_changeResolution(int width, int height, bool fullscreen);
bool Kore_System_handleMessages();
// TODO: Kore::System::mousePos not defined for Linux backend?
// vec2i Kore_System_mousePos();
void Kore_System_showKeyboard();
void Kore_System_hideKeyboard();
// TODO: Kore::System::showsKeyboard not defined for Linux backend?
// bool Kore_System_showsKeyboard();
void Kore_System_loadURL(const char* url);
int Kore_System_desktopWidth();
int Kore_System_desktopHeight();
const char* Kore_System_systemId();
void Kore_System_setTitle(const char* title);
const char* Kore_System_savePath();
const char** Kore_System_videoFormats();
void Kore_System_showWindow();
void Kore_System_swapBuffers(int contextId);
void Kore_System_makeCurrent(int contextId);
void Kore_System_clearCurrent();

double Kore_System_frequency();
ticks Kore_System_timestamp();
double Kore_System_time();

void Kore_System_setName(const char* name);
const char* Kore_System_name();

bool Kore_System_hasShowWindowFlag();
void Kore_System_setShowWindowFlag(bool value);

int Kore_System_simpleSetup(int argc, char* argv[],
							int width, int height,
							int antialiasing,
							WE_Kore_WindowMode mode,
							const char* title,
							bool showWindow);

void Kore_System_setup();
void Kore_System_start();
void Kore_System_stop();
void Kore_System__shutdown();
bool Kore_System_isFullscreen();

void Kore_System_setCallback(void (*value)());
void Kore_System_setForegroundCallback(void (*value)());
void Kore_System_setResumeCallback(void (*value)());
void Kore_System_setPauseCallback(void (*value)());
void Kore_System_setBackgroundCallback(void (*value)());
void Kore_System_setShutdownCallback(void (*value)());
void Kore_System_setOrientationCallback(void (*value)(WE_Kore_Orientation));
void Kore_System_setDropFilesCallback(void (*value)(wchar_t*));
void Kore_System_setKeepScreenOn(bool on);

void Kore_System_callback();
void Kore_System_foregroundCallback();
void Kore_System_resumeCallback();
void Kore_System_pauseCallback();
void Kore_System_backgroundCallback();
void Kore_System_shutdownCallback();
void Kore_System_orientationCallback(WE_Kore_Orientation orientation);
void Kore_System_dropFilesCallback(wchar_t* filePath);

/****************/





/**** Random ****/

// Kore::Random::init -0
// void Kore_Random_init(int seed);
void Kore_Random_init();

/****************/





/**** Graphics1 ****/

// Enums:

// Kore::Graphics1::ImageCompression
typedef enum WE_Kore_Graphics1_ImageCompression {
	WE_ImageCompressionNone = 0,
	WE_ImageCompressionDXT5 = 1,
	WE_ImageCompressionASTC = 2,
	WE_ImageCompressionPVRT = 3,
} WE_Kore_Graphics1_ImageCompression;

// Kore::Graphics1::Image::Format
typedef enum WE_Kore_Graphics1_Image_Format {
	WE_FormatRGBA32 = 0,
	WE_FormatGrey8 = 1,
	WE_FormatRGB24 = 2,
	WE_FormatRGBA128 = 3,
	WE_FormatRGBA64 = 4,
	WE_FormatA32 = 5,
	WE_FormatBGRA32 = 6,
	WE_FormatA16 = 7,
} WE_Kore_Graphics1_Image_Format;

// Classes:

/* Kore::Graphics1::Color */
struct WC_Kore_Graphics1_Color;
typedef	struct WC_Kore_Graphics1_Color WC_Kore_Graphics1_Color;
// .. constructors
WC_Kore_Graphics1_Color* Kore_Graphics1_Color_create(uint color);
// .. destructor, TODO: Kore_Graphics1_Color_destroy needed with no dynallocs?
void Kore_Graphics1_Color_destroy(WC_Kore_Graphics1_Color* self);
// .. static members
// TODO: A bunch of colors in hex

/* Kore::Graphics1::Image */
struct WC_Kore_Graphics1_Image;
typedef struct WC_Kore_Graphics1_Image WC_Kore_Graphics1_Image;
// .. constructors
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHFR(
	int width, int height, WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHDFR(
	int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createFR(
	const char* filename, bool readable);
// WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createRFR(
// 	WC_Kore_Reader& reader, const char* format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHFR(
	void* data, int width, int height,
	WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHDFR(
	void* data, int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
// .. destructor
void Kore_Graphics1_Image_destroy(WC_Kore_Graphics1_Image* self);
// .. methods
int Kore_Graphics1_Image_at(WC_Kore_Graphics1_Image* self, int x, int y);
// .. data access
int Kore_Graphics1_Image_width(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_height(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_depth(WC_Kore_Graphics1_Image* self);
WE_Kore_Graphics1_Image_Format Kore_Graphics1_Image_format(
	WC_Kore_Graphics1_Image* self);
bool Kore_Graphics1_Image_readable(WC_Kore_Graphics1_Image* self);
WE_Kore_Graphics1_ImageCompression Kore_Graphics1_Image_compression(
	WC_Kore_Graphics1_Image* self);
u8* Kore_Graphics1_Image_data(WC_Kore_Graphics1_Image* self);
float* Kore_Graphics1_Image_hdrData(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_dataSize(WC_Kore_Graphics1_Image* self);
unsigned Kore_Graphics1_Image_internalFormat(WC_Kore_Graphics1_Image* self);
// .. static members
int Kore_Graphics1_Image_sizeOf(WE_Kore_Graphics1_Image_Format format);

/*******************/





/**** Graphics2 ****/

// Enums:
//   Kore::Graphics2::ImageScaleQuality

// Classes:
//   Kore::Graphics2::Color? typedef'd from Kore::Graphics1::Color
//   Kore::Graphics2::Graphics2
//   Kore::Graphics2::ImageShaderPainter
//   Kore::Graphics2::ColoredShaderPainter
//   Kore::Graphics2::TextShaderPainter
//   Kore::Kravur stuff? see graphics2 Kravur.h

/*******************/





/**** Graphics4 ****/

// Enums:
//   Graphics.h
//     Kore::Graphics4::TextureAddressing
//     Kore::Graphics4::TextureFilter
//     Kore::Graphics4::MipmapFilter
//     Kore::Graphics4::RenderState
//     Kore::Graphics4::BlendingOperation
//     Kore::Graphics4::ZCompareMode
//     Kore::Graphics4::CullMode
//     Kore::Graphics4::TexDir
//     Kore::Graphics4::FogType
//     Kore::Graphics4::RenderTargetFormat
//     Kore::Graphics4::StencilAction
//     Kore::Graphics4::TextureOperation
//     Kore::Graphics4::TextureArgument
//   Shader.h
//     Kore::Graphics4::ShaderType
//   VertexStructure.h
//     Kore::Graphics4::VertexData
//     Kore::Graphics4::VertexAttribute

// Classes:
//   Graphics.h
//     Kore::Graphics4::PipelineState
//     Kore::Graphics4::TextureArray
//     Kore::Graphics4::VertexBuffer
//     Kore::Graphics4::IndexBuffer
//     Kore::Graphics4::RenderTarget
//   PipelineState.h
//     Kore::Graphics4::PipelineState
//   Shader.h
//     Kore::Graphics4::Shader
//     Kore::Graphics4::ConstantLocation
//   Texture.h
//     Kore::Graphics4::Image? typedef'd from Kore::Graphics1::Image
//     Kore::Graphics4::TextureUnit
//     Kore::Graphics4::Texture
//   TextureArray.h
//     Kore::Graphics4::TextureArray
//   VertexStructure.h
//     Kore::Graphics4::VertexElement
//     Kore::Graphics4::VertexStructure

// Functions:
void Kore_Graphics4_begin(int windowId);
void Kore_Graphics4_clear(uint flags, uint color, float depth, int stencil);
void Kore_Graphics4_end(int windowId);
void Kore_Graphics4_swapBuffers(int windowId);

/*******************/





#ifdef __cplusplus
}
#endif
