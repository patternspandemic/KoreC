#include <Kore/Window.h>
#include <Kore/System.h>
#include <Kore/Math/Random.h>
#include <Kore/Graphics4/Graphics.h>

#include <string.h>

#include "CWrapper.h"

/*
  Guard against enum changes.
*/

// Kore::WindowMode assertions
_Static_assert(sizeof(W_Kore_WindowMode) == sizeof(Kore::WindowMode),
  "Size of enum Kore::WindowMode changed.");
_Static_assert(W_WindowModeWindow == WindowModeWindow);
_Static_assert(W_WindowModeBorderless == WindowModeBorderless);
_Static_assert(W_WindowModeFullscreen == WindowModeFullscreen);

#ifdef __cplusplus
extern "C" {
#endif

/**** Window ****/

void Kore_RendererOptions_default(W_Kore_RendererOptions* ro) {
  ro->textureFormat = 0;
	ro->depthBufferBits = 16;
	ro->stencilBufferBits = 8;
  ro->antialiasing = 0;
}

void Kore_WindowOptions_default(W_Kore_WindowOptions* wo) {
  wo->title = "KoreWindow";
	wo->width = 800;
	wo->height = 600;
	wo->x = -1;
  wo->y = -1;
	wo->targetDisplay = -1;
	wo->vSync = true
	wo->resizable = false;
	wo->maximizable = false;
  wo->minimizable = true;
	wo->mode = W_WindowModeWindow;
	wo->showWindow = true
	wo->rendererOptions.antialiasing = 0;
}

/****************/
/**** System ****/

// // Kore::System::simpleSetup
// int Kore_System_simpleSetup(int argc, char* argv[], int width, int height, 
//                             int antialiasing, W_Kore_WindowMode mode, 
// 														const char* title, bool showWindow) {
//   mode = (Kore::WindowMode)mode;
//   return Kore::System::simpleSetup(argc, argv, width, height, antialiasing, 
//                                    mode, title, showWindow);
// }

// Kore::System::timestamp
// Kore::System::desktopWidth
// Kore::System::desktopHeight
// Kore::System::windowCount

// Kore::System::setName
void Kore_System_setName(const char* name) {
  Kore::System::setName(name);
}

// Kore::System::setup
void Kore_System_setup() {
  Kore::System::setup();
}

// Kore::System::initWindow
int Kore_System_initWindow(W_Kore_WindowOptions* options) {
  Kore::WindowOptions windowOptions;
  Kore::RendererOptions rendererOptions;

  windowOptions.title = malloc(strlen(options->title) + 1);
  strcpy(windowOptions.title, options->title);
  windowOptions.width = options->width;
  windowOptions.height = options->height;
  windowOptions.x = options->x;
  windowOptions.y = options->y;
  windowOptions.targetDisplay = options->targetDisplay;
  windowOptions.vSync = options->vSync;
  windowOptions.resizable = options->resizable;
  windowOptions.maximizable = options->maximizable;
  windowOptions.minimizable = options->minimizable;
  windowOptions.mode = (Kore::WindowMode)options->mode;
  windowOptions.showWindow = options->showWindow;

  rendererOptions.textureFormat = options->rendererOptions.textureFormat;
  rendererOptions.depthBufferBits = options->rendererOptions.depthBufferBits;
  rendererOptions.stencilBufferBits = options->rendererOptions.stencilBufferBits;
  rendererOptions.antialiasing = options->rendererOptions.antialiasing;
  windowOptions.rendererOptions = rendererOptions; 

  return Kore::System::initWindow(windowOptions);
}

// Kore::System::destroyWindow ?

// Kore::System::setCallback
void Kore_System_setCallback(void (*value)()) {
  Kore::System::setCallback(value);
}

// Kore::System::start
void Kore_System_start() {
  Kore::System::start();
}

// Kore::System::windowWidth
// Kore::System::windowHeight
// Kore::System::time
// Kore::System::stop

/****************/
/**** Random ****/

// Kore::Random::init
void Kore_Random_init(int seed) {
  Kore::Random::init(seed);
}

/****************/
/**** Graphics4 ****/

void Kore_Graphics4_begin(int windowId) {
  Kore::Graphics4::begin(windowId);
}

void Kore_Graphics4_clear(uint flags, uint color, float depth, int stencil) {
  Kore::Graphics4::clear(flags, color, depth, stencil);
}

void Kore_Graphics4_end(int windowId) {
  Kore::Graphics4::end(windowId);
}

void Kore_Graphics4_swapBuffers(int windowId) {
  Kore::Graphics4::swapBuffers(windowId);
}

/*******************/

#ifdef __cplusplus
}
#endif
