#include <Kore/pch.h>
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics4/PipelineState.h>
#include <Kore/Graphics4/Texture.h>
#include <Kore/Graphics2/Graphics.h>
#include <Kore/Graphics2/Kravur.h>

#include <assert.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::Graphics2::ImageScaleQuality assertions
static_assert(
  WE_ImageScaleQualityLow == Kore::Graphics2::ImageScaleQuality::Low,
	"Kore::Graphics2::ImageScaleQuality::Low enum value changed.");
static_assert(
  WE_ImageScaleQualityHigh == Kore::Graphics2::ImageScaleQuality::High,
	"Kore::Graphics2::ImageScaleQuality::High enum value changed.");

// TODO: Classes:
//   Kore::Graphics2::Color? typedef'd from Kore::Graphics1::Color
//   Kore::Graphics2::ImageShaderPainter
//   Kore::Graphics2::ColoredShaderPainter
//   Kore::Graphics2::TextShaderPainter

/* Kore::Graphics2::Graphics2 */

// .. constructors
WC_Kore_Graphics2_Graphics2* Kore_Graphics2_Graphics2_create(
	int width, int height, bool rTargets) {
  return reinterpret_cast<WC_Kore_Graphics2_Graphics2*>(
		new Kore::Graphics2::Graphics2(width, height, rTargets));
}

// .. destructor
void Kore_Graphics2_Graphics2_destroy(WC_Kore_Graphics2_Graphics2* self) {
  delete reinterpret_cast<Kore::Graphics2::Graphics2*>(self);
}

// .. methods
void Kore_Graphics2_Graphics2_drawTexture( // drawImage
	WC_Kore_Graphics2_Graphics2* self,
	WC_Kore_Graphics4_Texture* img,
	float x, float y) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawImage(
    reinterpret_cast<Kore::Graphics4::Texture*>(img),
    x, y);
}

void Kore_Graphics2_Graphics2_drawScaledSubTexture( // drawScaledSubImage
	WC_Kore_Graphics2_Graphics2* self,
	WC_Kore_Graphics4_Texture* img,
	float sx, float sy, float sw, float sh,
	float dx, float dy, float dw, float dh) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawScaledSubImage(
    reinterpret_cast<Kore::Graphics4::Texture*>(img),
    sx, sy, sw, sh, dx, dy, dw, dh);
}

void Kore_Graphics2_Graphics2_drawRenderTarget( // drawImage
	WC_Kore_Graphics2_Graphics2* self,
	WC_Kore_Graphics4_RenderTarget* img,
	float x, float y) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawImage(
    reinterpret_cast<Kore::Graphics4::RenderTarget*>(img),
    x, y);
}

void Kore_Graphics2_Graphics2_drawScaledSubRenderTarget( // drawScaledSubImage
	WC_Kore_Graphics2_Graphics2* self,
	WC_Kore_Graphics4_RenderTarget* img,
	float sx, float sy, float sw, float sh,
	float dx, float dy, float dw, float dh) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawScaledSubImage(
    reinterpret_cast<Kore::Graphics4::RenderTarget*>(img),
    sx, sy, sw, sh, dx, dy, dw, dh);
}

void Kore_Graphics2_Graphics2_drawRect(
	WC_Kore_Graphics2_Graphics2* self,
	float x, float y, float width, float height, float strength) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawRect(
    x, y, width, height, strength);
}

void Kore_Graphics2_Graphics2_fillRect(
	WC_Kore_Graphics2_Graphics2* self,
	float x, float y, float width, float height) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->fillRect(
    x, y, width, height);
}

void Kore_Graphics2_Graphics2_drawStringTXY(
	WC_Kore_Graphics2_Graphics2* self,
	const char* text, float x, float y) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawString(
    text, x, y);
}

void Kore_Graphics2_Graphics2_drawStringTLXY(
	WC_Kore_Graphics2_Graphics2* self,
	const char* text, int length, float x, float y) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawString(
    text, length, x, y);
}

void Kore_Graphics2_Graphics2_drawStringTSLXY(
	WC_Kore_Graphics2_Graphics2* self,
	const char* text, int start, int length, float x, float y) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawString(
    text, start, length, x, y);
}

void Kore_Graphics2_Graphics2_drawLine(
	WC_Kore_Graphics2_Graphics2* self,
	float x1, float y1, float x2, float y2, float strength) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawLine(
    x1, y1, x2, y2, strength);
}

void Kore_Graphics2_Graphics2_fillTriangle(
	WC_Kore_Graphics2_Graphics2* self,
	float x1, float y1, float x2, float y2, float x3, float y3) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->fillTriangle(
    x1, y1, x2, y2, x3, y3);
}

void Kore_Graphics2_Graphics2_setPipeline(
	WC_Kore_Graphics2_Graphics2* self,
	WC_Kore_Graphics4_PipelineState* pipeline) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setPipeline(
    reinterpret_cast<Kore::Graphics4::PipelineState*>(pipeline));
}

void Kore_Graphics2_Graphics2_scissor(
	WC_Kore_Graphics2_Graphics2* self,
	int x, int y, int width, int height) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->scissor(
    x, y, width, height);
}

void Kore_Graphics2_Graphics2_disableScissor(
  WC_Kore_Graphics2_Graphics2* self) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->disableScissor();
}

void Kore_Graphics2_Graphics2_begin(
	WC_Kore_Graphics2_Graphics2* self,
	bool renderTargets, int width, int height, bool clear, uint clearColor) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->begin(
    renderTargets, width, height, clear, clearColor);
}

void Kore_Graphics2_Graphics2_clear(
	WC_Kore_Graphics2_Graphics2* self,
	uint color) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->clear(color);
}

void Kore_Graphics2_Graphics2_flush(WC_Kore_Graphics2_Graphics2* self) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->flush();
}

void Kore_Graphics2_Graphics2_end(WC_Kore_Graphics2_Graphics2* self) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->end();
}

// TODO: Equiv Video Type, impl in Kore unfinished?
// void Kore_Graphics2_Graphics2_drawVideoInternal(
// 	WC_Kore_Graphics2_Graphics2* self,
// 	/*Video video,*/ float x, float y, float width, float height) {
//   reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawVideoInternal(
//     /*Video video,*/ x, y, width, height);
// }

// void Kore_Graphics2_Graphics2_drawVideo(
// 	WC_Kore_Graphics2_Graphics2* self,
// 	/*Video video,*/ float x, float y, float width, float height) {
//   reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->drawVideo(
//     /*Video video,*/ x, y, width, height);
// }

uint Kore_Graphics2_Graphics2_getColor(
	WC_Kore_Graphics2_Graphics2* self) {
  return reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getColor();
} //const

void Kore_Graphics2_Graphics2_setColor(
	WC_Kore_Graphics2_Graphics2* self, uint color) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setColor(color);
}

float Kore_Graphics2_Graphics2_getOpacity(
	WC_Kore_Graphics2_Graphics2* self) {
  return reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getOpacity();
} //const

void Kore_Graphics2_Graphics2_setOpacity(
	WC_Kore_Graphics2_Graphics2* self, float opacity) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setOpacity(
    opacity);
}

WE_Kore_Graphics2_ImageScaleQuality Kore_Graphics2_Graphics2_getImageScaleQuality(
  WC_Kore_Graphics2_Graphics2* self) {
  return (WE_Kore_Graphics2_ImageScaleQuality)reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getImageScaleQuality();
} //const

void Kore_Graphics2_Graphics2_setImageScaleQuality(
  WC_Kore_Graphics2_Graphics2* self,
	WE_Kore_Graphics2_ImageScaleQuality value) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setImageScaleQuality(
    (Kore::Graphics2::ImageScaleQuality)value);
}

WE_Kore_Graphics2_ImageScaleQuality Kore_Graphics2_Graphics2_getMipmapScaleQuality(
  WC_Kore_Graphics2_Graphics2* self) {
  return (WE_Kore_Graphics2_ImageScaleQuality)reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getMipmapScaleQuality();
} //const

void Kore_Graphics2_Graphics2_setMipmapScaleQuality(
  WC_Kore_Graphics2_Graphics2* self,
	WE_Kore_Graphics2_ImageScaleQuality value) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setMipmapScaleQuality(
    (Kore::Graphics2::ImageScaleQuality)value);
}

WC_Kore_Kravur* Kore_Graphics2_Graphics2_getFont(
	WC_Kore_Graphics2_Graphics2* self) {
  return reinterpret_cast<WC_Kore_Kravur*>(
    reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getFont());
} //const

void Kore_Graphics2_Graphics2_setFont(
	WC_Kore_Graphics2_Graphics2* self, WC_Kore_Kravur* font) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setFont(
    reinterpret_cast<Kore::Kravur*>(font));
}

int Kore_Graphics2_Graphics2_getFontSize(
	WC_Kore_Graphics2_Graphics2* self) {
  return reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getFontSize();
} //const

void Kore_Graphics2_Graphics2_setFontSize(
	WC_Kore_Graphics2_Graphics2* self, int value) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setFontSize(value);
}

uint Kore_Graphics2_Graphics2_getFontColor(
	WC_Kore_Graphics2_Graphics2* self) {
  return reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->getFontColor();
} //const

void Kore_Graphics2_Graphics2_setFontColor(
	WC_Kore_Graphics2_Graphics2* self, uint color) {
  reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->setFontColor(color);
}

// .. data accessors, TODO: Setter needed?
// TODO: mat3 to wrapped equiv
// WC_Kore_Mat3* Kore_Graphics2_Graphics2_getTransformation(
// 	WC_Kore_Graphics2_Graphics2* self) {}

void Kore_Graphics2_Graphics2_getTransformationElements(
	WC_Kore_Graphics2_Graphics2* self,
	KC_Mat3ElementsHelper* mat3ElementsOut) {
  Kore::mat3* transform =
    &(reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->transformation);
  mat3ElementsOut->e00 = transform->get(0, 0); mat3ElementsOut->e10 = transform->get(0, 1); mat3ElementsOut->e20 = transform->get(0, 2);
	mat3ElementsOut->e01 = transform->get(1, 0); mat3ElementsOut->e11 = transform->get(1, 1); mat3ElementsOut->e21 = transform->get(1, 2);
	mat3ElementsOut->e02 = transform->get(2, 0); mat3ElementsOut->e12 = transform->get(2, 1); mat3ElementsOut->e22 = transform->get(2, 2);
}

// TODO: mat3 to wrapped equiv
// void Kore_Graphics2_Graphics2_setTransformation(
// 	WC_Kore_Graphics2_Graphics2* self, WC_Kore_Mat3* transformation) {}

void Kore_Graphics2_Graphics2_setTransformationElements(
	WC_Kore_Graphics2_Graphics2* self,
	KC_Mat3ElementsHelper* mat3Elements) {
  Kore::mat3* transform =
    &(reinterpret_cast<Kore::Graphics2::Graphics2*>(self)->transformation);
  transform->Set(0, 0, mat3Elements->e00); transform->Set(0, 1, mat3Elements->e10); transform->Set(0, 2, mat3Elements->e20);
	transform->Set(1, 0, mat3Elements->e01); transform->Set(1, 1, mat3Elements->e11); transform->Set(1, 2, mat3Elements->e21);
	transform->Set(2, 0, mat3Elements->e02); transform->Set(2, 1, mat3Elements->e12); transform->Set(2, 2, mat3Elements->e22);
}


/* Kore::Kravur */

// .. destructor
void Kore_Kravur_destroy(WC_Kore_Kravur* self) {
  delete reinterpret_cast<Kore::Kravur*>(self);
}

// .. methods
WC_Kore_Graphics4_Texture* Kore_Kravur_getTexture(WC_Kore_Kravur* self) {
  return reinterpret_cast<WC_Kore_Graphics4_Texture*>(
    reinterpret_cast<Kore::Kravur*>(self)->getTexture());
}

void Kore_Kravur_getBakedQuad(
	WC_Kore_Kravur* self,
  int char_index, float xpos, float ypos,
  WS_AlignedQuad* alignedQuadOut) {
  AlignedQuad bakedQuad;
  bakedQuad = reinterpret_cast<Kore::Kravur*>(self)->getBakedQuad(
    char_index, xpos, ypos);
  alignedQuadOut->x0 = bakedQuad.x0;
	alignedQuadOut->y0 = bakedQuad.y0;
	alignedQuadOut->s0 = bakedQuad.s0;
	alignedQuadOut->t0 = bakedQuad.t0;
	alignedQuadOut->x1 = bakedQuad.x1;
	alignedQuadOut->y1 = bakedQuad.y1;
	alignedQuadOut->s1 = bakedQuad.s1;
	alignedQuadOut->t1 = bakedQuad.t1;
  alignedQuadOut->xadvance = bakedQuad.xadvance;
}

float Kore_Kravur_getSize(WC_Kore_Kravur* self) {
  return reinterpret_cast<Kore::Kravur*>(self)->getHeight();
}

float Kore_Kravur_charsWidth(
	WC_Kore_Kravur* self, const char* ch, int offset, int length) {
  return reinterpret_cast<Kore::Kravur*>(self)->charsWidth(ch, offset, length);
}

float Kore_Kravur_stringWidth(
	WC_Kore_Kravur* self, const char* string, int length) {
  return reinterpret_cast<Kore::Kravur*>(self)->stringWidth(string, length);
} //int length = -1

float Kore_Kravur_getBaselinePosition(WC_Kore_Kravur* self) {
  return reinterpret_cast<Kore::Kravur*>(self)->getBaselinePosition();
}

// .. data accessors
int Kore_Kravur_getWidth(WC_Kore_Kravur* self) {
  return reinterpret_cast<Kore::Kravur*>(self)->width;
}

int Kore_Kravur_getHeight(WC_Kore_Kravur* self) {
  return reinterpret_cast<Kore::Kravur*>(self)->height;
}

// .. static members
WC_Kore_Kravur* Kore_Kravur_load(
	const char* name, WS_FontStyle* style, float size) {
  FontStyle fontStyle;
  fontStyle.bold = style->bold;
  fontStyle.italic = style->italic;
  fontStyle.underlined = style->underlined;
  return reinterpret_cast<WC_Kore_Kravur*>(
		Kore::Kravur::load(name, fontStyle, size));
}


#ifdef __cplusplus
}
#endif
