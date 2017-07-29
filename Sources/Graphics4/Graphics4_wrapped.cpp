#include <Kore/pch.h>
#include <Kore/Graphics4/Graphics.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif
