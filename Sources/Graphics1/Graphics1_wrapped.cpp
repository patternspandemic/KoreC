#include <Kore/pch.h>
#include <Kore/Graphics1/Color.h>
#include <Kore/Graphics1/Image.h>

#include <assert.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::Graphics1::ImageCompression assertions
static_assert(WE_ImageCompressionNone == Kore::Graphics1::ImageCompressionNone,
	"Kore::Graphics1::ImageCompressionNone enum value changed.");
static_assert(WE_ImageCompressionDXT5 == Kore::Graphics1::ImageCompressionDXT5,
	"Kore::Graphics1::ImageCompressionDXT5 enum value changed.");
static_assert(WE_ImageCompressionASTC == Kore::Graphics1::ImageCompressionASTC,
	"Kore::Graphics1::ImageCompressionASTC enum value changed.");
static_assert(
	WE_ImageCompressionPVRTC == Kore::Graphics1::ImageCompressionPVRTC,
	"Kore::Graphics1::ImageCompressionPVRTC enum value changed.");

// Kore::Graphics1::Image::Format assertions
static_assert(WE_FormatRGBA32 == Kore::Graphics1::Image::RGBA32,
	"Kore::Graphics1::Image::RGBA32 enum value changed.");
static_assert(WE_FormatGrey8 == Kore::Graphics1::Image::Grey8,
	"Kore::Graphics1::Image::Grey8 enum value changed.");
static_assert(WE_FormatRGB24 == Kore::Graphics1::Image::RGB24,
	"Kore::Graphics1::Image::RGB24 enum value changed.");
static_assert(WE_FormatRGBA128 == Kore::Graphics1::Image::RGBA128,
	"Kore::Graphics1::Image::RGBA128 enum value changed.");
static_assert(WE_FormatRGBA64 == Kore::Graphics1::Image::RGBA64,
	"Kore::Graphics1::Image::RGBA64 enum value changed.");
static_assert(WE_FormatA32 == Kore::Graphics1::Image::A32,
	"Kore::Graphics1::Image::A32 enum value changed.");
static_assert(WE_FormatBGRA32 == Kore::Graphics1::Image::BGRA32,
	"Kore::Graphics1::Image::BGRA32 enum value changed.");
static_assert(WE_FormatA16 == Kore::Graphics1::Image::A16,
	"Kore::Graphics1::Image::A16 enum value changed.");

/* Kore::Graphics1::Color */

// .. constructors
WC_Kore_Graphics1_Color* Kore_Graphics1_Color_create(uint color) {
	return reinterpret_cast<WC_Kore_Graphics1_Color*>(
		new Kore::Graphics1::Color(color));
}

// .. destructor, TODO: Kore_Graphics1_Color_destroy needed with no dynallocs?
void Kore_Graphics1_Color_destroy(WC_Kore_Graphics1_Color* self) {
	delete reinterpret_cast<Kore::Graphics1::Color*>(self);
}

// .. static members
// TODO: A bunch of colors in hex, perhaps not useful


/* Kore::Graphics1::Image */

// .. constructors
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHFR(
	int width, int height, WE_Kore_Graphics1_Image_Format format, bool readable) {
	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
		new Kore::Graphics1::Image(
			width, height, (Kore::Graphics1::Image::Format)format, readable));
}

WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHDFR(
	int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
		new Kore::Graphics1::Image(
			width, height, depth, (Kore::Graphics1::Image::Format)format, readable));
}

WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createFR(
	const char* filename, bool readable) {
	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
		new Kore::Graphics1::Image(filename, readable));
}

// TODO: Check reader param syntax & need to expose Reader class if useful?
// WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createRFR(
// 	WC_Kore_Reader& reader, const char* format, bool readable) {
// 	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
// 		new Kore::Graphics1::Image(reader, format, readable));
// }

WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHFR(
	void* data, int width, int height,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
		new Kore::Graphics1::Image(
			data, width, height, (Kore::Graphics1::Image::Format)format, readable));
}

WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHDFR(
	void* data, int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable) {
	return reinterpret_cast<WC_Kore_Graphics1_Image*>(
		new Kore::Graphics1::Image(
			data, width, height, depth,
			(Kore::Graphics1::Image::Format)format, readable));
}

// .. destructor
void Kore_Graphics1_Image_destroy(WC_Kore_Graphics1_Image* self) {
	delete reinterpret_cast<Kore::Graphics1::Image*>(self);
}

// .. methods
int Kore_Graphics1_Image_at(WC_Kore_Graphics1_Image* self, int x, int y) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->at(x, y);
}

// .. data access
int Kore_Graphics1_Image_getWidth(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->width;
}

int Kore_Graphics1_Image_getHeight(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->height;
}

int Kore_Graphics1_Image_getDepth(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->depth;
}

WE_Kore_Graphics1_Image_Format Kore_Graphics1_Image_getFormat(
	WC_Kore_Graphics1_Image* self) {
	return (WE_Kore_Graphics1_Image_Format)reinterpret_cast<Kore::Graphics1::Image*>(self)->format;
}

bool Kore_Graphics1_Image_getReadable(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->readable;
}

WE_Kore_Graphics1_ImageCompression Kore_Graphics1_Image_getCompression(
	WC_Kore_Graphics1_Image* self) {
	return (WE_Kore_Graphics1_ImageCompression)reinterpret_cast<Kore::Graphics1::Image*>(self)->compression;
}

u8* Kore_Graphics1_Image_getData(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->data;
}

float* Kore_Graphics1_Image_getHdrData(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->hdrData;
}

int Kore_Graphics1_Image_getDataSize(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->dataSize;
}

unsigned Kore_Graphics1_Image_getInternalFormat(WC_Kore_Graphics1_Image* self) {
	return reinterpret_cast<Kore::Graphics1::Image*>(self)->internalFormat;
}

// .. static members
int Kore_Graphics1_Image_sizeOf(WE_Kore_Graphics1_Image_Format format) {
  return Kore::Graphics1::Image::sizeOf((Kore::Graphics1::Image::Format)format);
}

#ifdef __cplusplus
}
#endif
