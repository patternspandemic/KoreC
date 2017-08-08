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
//   Kore::Graphics2::Graphics2
//   Kore::Graphics2::ImageShaderPainter
//   Kore::Graphics2::ColoredShaderPainter
//   Kore::Graphics2::TextShaderPainter
//   Kore::Kravur stuff? see graphics2 Kravur.h

#ifdef __cplusplus
}
#endif
