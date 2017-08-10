#include <Kore/pch.h>
#include <Kore/Graphics1/Image.h>
#include <Kore/Graphics4/TextureArray.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Kore::Graphics4::TextureArray */

// .. constructors
// TODO: Verify proper handling of WC_Kore_Graphics1_Image**
WC_Kore_Graphics4_TextureArray* Kore_Graphics4_TextureArray_create(
	WC_Kore_Graphics1_Image** textures, int count) {
  return reinterpret_cast<WC_Kore_Graphics4_TextureArray*>(
		new Kore::Graphics4::TextureArray(
      reinterpret_cast<Kore::Graphics1::Image**>(textures), count));
}

// .. destructor
void Kore_Graphics4_TextureArray_destroy(
	WC_Kore_Graphics4_TextureArray* self) {
  delete reinterpret_cast<Kore::Graphics4::TextureArray*>(self);
}

#ifdef __cplusplus
}
#endif
