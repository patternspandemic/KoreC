#include <Kore/pch.h>
#include <Kore/Window.h>
#include <Kore/System.h>

#include "CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

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

  windowOptions.title = options->title;
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

#ifdef __cplusplus
}
#endif
