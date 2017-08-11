#include <Kore/pch.h>
#include <Kore/Graphics4/Texture.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Kore::Graphics4::TextureUnit */

// .. constructors
WC_Kore_Graphics4_TextureUnit* Kore_Graphics4_TextureUnit_create() {
  return reinterpret_cast<WC_Kore_Graphics4_TextureUnit*>(
		new Kore::Graphics4::TextureUnit());
}

// .. destructor
void Kore_Graphics4_TextureUnit_destroy(
	WC_Kore_Graphics4_TextureUnit* self) {
  delete reinterpret_cast<Kore::Graphics4::TextureUnit*>(self);
}

/* Kore::Graphics4::Texture */

// .. constructors
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createWHFR(
	int width, int height, WE_Kore_Graphics1_Image_Format format, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(
			width, height, (Kore::Graphics1::Image::Format)format, readable));
}

WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createWHDFR(
	int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(
			width, height, depth, (Kore::Graphics1::Image::Format)format, readable));
}

// TODO: Check reader param syntax & need to expose Reader class if useful?
// WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createRFR(
// 	WC_Kore_Reader& reader, const char* format, bool readable) {
// 	return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
// 		new Kore::Graphics4::Texture(reader, format, readable));
// }

WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createFR(
	const char* filename, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(filename, readable));
}

WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDSFR(
	void* data, int size, const char* format, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(data, size, format, readable));
}

WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDWHFR(
	void* data, int width, int height,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(
			data, width, height, (Kore::Graphics1::Image::Format)format, readable));
}

WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDWHDFR(
	void* data, int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
		new Kore::Graphics4::Texture(
			data, width, height, depth,
			(Kore::Graphics1::Image::Format)format, readable));
}

// .. destructor
void Kore_Graphics4_Texture_destroy(
	WC_Kore_Graphics4_Texture* self) {
  delete reinterpret_cast<Kore::Graphics4::Texture*>(self);
}

// .. methods
void Kore_Graphics4_Texture__set(
	WC_Kore_Graphics4_Texture* self, WC_Kore_Graphics4_TextureUnit* unit) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->_set(
    *reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit));
}

void Kore_Graphics4_Texture__setImage(
	WC_Kore_Graphics4_Texture* self, WC_Kore_Graphics4_TextureUnit* unit) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->_setImage(
    *reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit));
}

u8* Kore_Graphics4_Texture_lock(WC_Kore_Graphics4_Texture* self) {
  return reinterpret_cast<Kore::Graphics4::Texture*>(self)->lock();
}

void Kore_Graphics4_Texture_unlock(WC_Kore_Graphics4_Texture* self) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->unlock();
}

void Kore_Graphics4_Texture_clear(
	WC_Kore_Graphics4_Texture* self,
	int x, int y, int z, int width, int height,
	int depth, uint color) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->clear(
    x, y, z, width, height, depth, color);
}

#if defined(KORE_IOS) || defined(KORE_MACOS)
void Kore_Graphics4_Texture_upload(
	WC_Kore_Graphics4_Texture* self,
	u8* data, int stride) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->upload(data, stride);
}
#endif

void Kore_Graphics4_Texture_generateMipmaps(
	WC_Kore_Graphics4_Texture* self, int levels) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->generateMipmaps(levels);
}

void Kore_Graphics4_Texture_setMipmap(
	WC_Kore_Graphics4_Texture* self,
	WC_Kore_Graphics4_Texture* mipmap, int level) {
  reinterpret_cast<Kore::Graphics4::Texture*>(self)->setMipmap(
    reinterpret_cast<Kore::Graphics4::Texture*>(mipmap), level);
}

int Kore_Graphics4_Texture_stride(WC_Kore_Graphics4_Texture* self) {
  return reinterpret_cast<Kore::Graphics4::Texture*>(self)->stride();
}

// .. data access
int Kore_Graphics4_Texture_getTexWidth(WC_Kore_Graphics4_Texture* self) {
  return reinterpret_cast<Kore::Graphics4::Texture*>(self)->texWidth;
}

int Kore_Graphics4_Texture_getTexHeight(WC_Kore_Graphics4_Texture* self) {
  return reinterpret_cast<Kore::Graphics4::Texture*>(self)->texHeight;
}

int Kore_Graphics4_Texture_getTexDepth(WC_Kore_Graphics4_Texture* self) {
  return reinterpret_cast<Kore::Graphics4::Texture*>(self)->texDepth;
}

#ifdef __cplusplus
}
#endif
