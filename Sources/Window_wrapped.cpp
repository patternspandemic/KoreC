#include <Kore/pch.h>
#include <Kore/Window.h>

#include <assert.h>

#include "CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::WindowMode assertions
static_assert(WE_WindowModeWindow == Kore::WindowModeWindow,
	"Kore::WindowModeWindow enum value changed.");
static_assert(WE_WindowModeBorderless == Kore::WindowModeBorderless,
	"Kore::WindowModeBorderless enum value changed.");
static_assert(WE_WindowModeFullscreen == Kore::WindowModeFullscreen,
	"Kore::WindowModeFullscreen enum value changed.");

void Kore_RendererOptions_default(WS_Kore_RendererOptions* ro) {
  ro->textureFormat = 0;
	ro->depthBufferBits = 16;
	ro->stencilBufferBits = 8;
  ro->antialiasing = 0;
}

void Kore_WindowOptions_default(WS_Kore_WindowOptions* wo) {
  wo->title = "KoreWindow";
	wo->width = 800;
	wo->height = 600;
	wo->x = -1;
  wo->y = -1;
	wo->targetDisplay = -1;
	wo->vSync = true;
	wo->resizable = false;
	wo->maximizable = false;
  wo->minimizable = true;
	wo->mode = WE_WindowModeWindow;
	wo->showWindow = true;
	wo->rendererOptions.antialiasing = 0;
}

#ifdef __cplusplus
}
#endif
