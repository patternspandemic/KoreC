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

// // Kore::System::simpleSetup
// int Kore_System_simpleSetup(int argc, char* argv[],
// 														int width, int height,
// 														int antialiasing,
// 														W_Kore_WindowMode mode,
// 														const char* title,
// 														bool showWindow);

// Kore::System::timestamp
// Kore::System::desktopWidth
// Kore::System::desktopHeight
// Kore::System::windowCount

// Kore::System::setName -1
void Kore_System_setName(const char* name);

// Kore::System::setup -2
void Kore_System_setup();

// Kore::System::initWindow -3
int Kore_System_initWindow(W_Kore_WindowOptions* options);

// Kore::System::destroyWindow ?

// Kore::System::setCallback -4
void Kore_System_setCallback(void (*value)());

// Kore::System::start -5
void Kore_System_start();

// Kore::System::windowWidth
// Kore::System::windowHeight
// Kore::System::time
// Kore::System::stop

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
