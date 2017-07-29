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
struct W_Kore_RendererOptions;
typedef struct W_Kore_RendererOptions {
	int textureFormat;
	int depthBufferBits;
	int stencilBufferBits;
	int antialiasing;
} W_Kore_RendererOptions;

void Kore_RendererOptions_default(W_Kore_RendererOptions* ro);

// Kore::WindowMode
typedef enum W_Kore_WindowMode {
	W_WindowModeWindow = 0,
	W_WindowModeBorderless = 1,
	W_WindowModeFullscreen = 2,
} W_Kore_WindowMode;

// Kore::WindowOptions
struct W_Kore_WindowOptions;
typedef struct W_Kore_WindowOptions {
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
	W_Kore_WindowMode mode;
	bool showWindow;
	W_Kore_RendererOptions rendererOptions;
} W_Kore_WindowOptions;

void Kore_WindowOptions_default(W_Kore_WindowOptions* wo);

/****************/
/**** System ****/

typedef unsigned long long ticks;

// Kore::Orientation
typedef enum W_Kore_Orientation {
	W_OrientationLandscapeLeft = 0,
	W_OrientationLandscapeRight = 1,
	W_OrientationPortrait = 2,
	W_OrientationPortraitUpsideDown = 3,
	W_OrientationUnknown = 4,
} W_Kore_Orientation;

void Kore_System_init(const char* name, int width, int height);

int Kore_System_currentDevice();

int Kore_System_initWindow(W_Kore_WindowOptions* options);
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
							W_Kore_WindowMode mode,
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
// TODO: How to switch W_Kore_Orientation to Kore::Orientation for Kore::System::setOrientationCallback?
// void Kore_System_setOrientationCallback(void (*value)(W_Kore_Orientation));
void Kore_System_setDropFilesCallback(void (*value)(wchar_t*));
void Kore_System_setKeepScreenOn(bool on);

void Kore_System_callback();
void Kore_System_foregroundCallback();
void Kore_System_resumeCallback();
void Kore_System_pauseCallback();
void Kore_System_backgroundCallback();
void Kore_System_shutdownCallback();
void Kore_System_orientationCallback(W_Kore_Orientation orientation);
void Kore_System_dropFilesCallback(wchar_t* filePath);

/****************/
/**** Random ****/

// Kore::Random::init -0
// void Kore_Random_init(int seed);
void Kore_Random_init();

/****************/
/**** Graphics4 ****/

void Kore_Graphics4_begin(int windowId);
void Kore_Graphics4_clear(uint flags, uint color, float depth, int stencil);
void Kore_Graphics4_end(int windowId);
void Kore_Graphics4_swapBuffers(int windowId);

/*******************/

#ifdef __cplusplus
}
#endif
