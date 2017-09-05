#include <Kore/pch.h>
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
	int width, int height, bool rTargets);

// .. destructor
void Kore_Graphics2_Graphics2_destroy(WC_Kore_Graphics2_Graphics2* self);

// .. methods
void Kore_Graphics2_Graphics2_drawTexture( // drawImage
	WC_Kore_Graphics4_Texture* img,
	float x, float y);
void Kore_Graphics2_Graphics2_drawScaledSubTexture( // drawScaledSubImage
	WC_Kore_Graphics4_Texture* img,
	float sx, float sy, float sw, float sh,
	float dx, float dy, float dw, float dh);
void Kore_Graphics2_Graphics2_drawRenderTarget( // drawImage
	WC_Kore_Graphics4_RenderTarget* img,
	float x, float y);
void Kore_Graphics2_Graphics2_drawScaledSubRenderTarget( // drawScaledSubImage
	WC_Kore_Graphics4_RenderTarget* img,
	float sx, float sy, float sw, float sh,
	float dx, float dy, float dw, float dh);
void Kore_Graphics2_Graphics2_drawRect(
	float x, float y, float width, float height, float strength);
void Kore_Graphics2_Graphics2_fillRect(
	float x, float y, float width, float height);
void Kore_Graphics2_Graphics2_drawStringTXY(const char* text, float x, float y);
void Kore_Graphics2_Graphics2_drawStringTLXY(
	const char* text, int length, float x, float y);
void Kore_Graphics2_Graphics2_drawLine(
	float x1, float y1, float x2, float y2, float strength);
void Kore_Graphics2_Graphics2_fillTriangle(
	float x1, float y1, float x2, float y2, float x3, float y3);
void Kore_Graphics2_Graphics2_setPipeline(
	WC_Kore_Graphics4_PipelineState* pipeline);
void Kore_Graphics2_Graphics2_scissor(int x, int y, int width, int height);
void Kore_Graphics2_Graphics2_disableScissor();
void Kore_Graphics2_Graphics2_begin(
	bool renderTargets, int width, int height, bool clear, uint clearColor);
void Kore_Graphics2_Graphics2_clear(uint color);
void Kore_Graphics2_Graphics2_flush();
void Kore_Graphics2_Graphics2_end();
// TODO: Equiv Video Type
// void Kore_Graphics2_Graphics2_drawVideoInternal(
// 	/*Video video,*/ float x, float y, float width, float height);
// void Kore_Graphics2_Graphics2_drawVideo(
// 	/*Video video,*/ float x, float y, float width, float height);
uint Kore_Graphics2_Graphics2_getColor(); //const
void Kore_Graphics2_Graphics2_setColor(uint color);
float Kore_Graphics2_Graphics2_getOpacity(); //const
void Kore_Graphics2_Graphics2_setOpacity(float opacity);
// TODO: Equiv Kravur type
// Kravur* Kore_Graphics2_Graphics2_getFont(); //const
// void Kore_Graphics2_Graphics2_setFont(Kravur* font);
int Kore_Graphics2_Graphics2_getFontSize(); //const
void Kore_Graphics2_Graphics2_setFontSize(int value);
uint Kore_Graphics2_Graphics2_getFontColor(); //const
void Kore_Graphics2_Graphics2_setFontColor(uint color);
// TODO: Graphics2 extended methods as found in Kha

// .. data accessors, TODO: Setter needed?
// TODO: mat3 to wrapped equiv
// WC_Kore_Mat3* Kore_Graphics2_Graphics2_getTransformation();
// void Kore_Graphics2_Graphics2_setTransformation(WC_Kore_Mat3* transformation);


//   Kore::Kravur stuff? see graphics2 Kravur.h

#ifdef __cplusplus
}
#endif
