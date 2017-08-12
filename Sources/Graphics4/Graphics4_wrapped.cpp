#include <Kore/pch.h>
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics4/Shader.h>
#include <Kore/Graphics4/Texture.h>
#include <Kore/Graphics4/VertexStructure.h>

#include <assert.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::Graphics4::TextureAddressing assertions
static_assert(
  WE_TextureAddressingRepeat == Kore::Graphics4::TextureAddressing::Repeat,
  "Kore::Graphics4::TextureAddressing::Repeat enum value changed.");
static_assert(
  WE_TextureAddressingMirror == Kore::Graphics4::TextureAddressing::Mirror,
  "Kore::Graphics4::TextureAddressing::Mirror enum value changed.");
static_assert(
  WE_TextureAddressingClamp == Kore::Graphics4::TextureAddressing::Clamp,
  "Kore::Graphics4::TextureAddressing::Clamp enum value changed.");
static_assert(
  WE_TextureAddressingBorder == Kore::Graphics4::TextureAddressing::Border,
  "Kore::Graphics4::TextureAddressing::Border enum value changed.");

// Kore::Graphics4::TextureFilter assertions
static_assert(
  WE_TextureFilterPointFilter == Kore::Graphics4::TextureFilter::PointFilter,
  "Kore::Graphics4::TextureFilter::PointFilter enum value changed.");
static_assert(
  WE_TextureFilterLinearFilter == Kore::Graphics4::TextureFilter::LinearFilter,
  "Kore::Graphics4::TextureFilter::LinearFilter enum value changed.");
static_assert(
  WE_TextureFilterAnisotropicFilter == Kore::Graphics4::TextureFilter::AnisotropicFilter,
  "Kore::Graphics4::TextureFilter::AnisotropicFilter enum value changed.");

// Kore::Graphics4::MipmapFilter assertions
static_assert(
  WE_MipmapFilterNoMipFilter == Kore::Graphics4::MipmapFilter::NoMipFilter,
  "Kore::Graphics4::MipmapFilter::NoMipFilter enum value changed.");
static_assert(
  WE_MipmapFilterPointMipFilter == Kore::Graphics4::MipmapFilter::PointMipFilter,
  "Kore::Graphics4::MipmapFilter::PointMipFilter enum value changed.");
static_assert(
  WE_MipmapFilterLinearMipFilter == Kore::Graphics4::MipmapFilter::LinearMipFilter,
  "Kore::Graphics4::MipmapFilter::LinearMipFilter enum value changed.");

// Kore::Graphics4::RenderState assertions
static_assert(
  WE_RenderStateBlendingState == Kore::Graphics4::RenderState::BlendingState,
  "Kore::Graphics4::RenderState::BlendingState enum value changed.");
static_assert(
  WE_RenderStateDepthTest == Kore::Graphics4::RenderState::DepthTest,
  "Kore::Graphics4::RenderState::DepthTest enum value changed.");
static_assert(
  WE_RenderStateDepthTestCompare == Kore::Graphics4::RenderState::DepthTestCompare,
  "Kore::Graphics4::RenderState::DepthTestCompare enum value changed.");
static_assert(
  WE_RenderStateDepthWrite == Kore::Graphics4::RenderState::DepthWrite,
  "Kore::Graphics4::RenderState::DepthWrite enum value changed.");
static_assert(
  WE_RenderStateNormalize == Kore::Graphics4::RenderState::Normalize,
  "Kore::Graphics4::RenderState::Normalize enum value changed.");
static_assert(
  WE_RenderStateBackfaceCulling == Kore::Graphics4::RenderState::BackfaceCulling,
  "Kore::Graphics4::RenderState::BackfaceCulling enum value changed.");
static_assert(
  WE_RenderStateScissorTestState == Kore::Graphics4::RenderState::ScissorTestState,
  "Kore::Graphics4::RenderState::ScissorTestState enum value changed.");
static_assert(
  WE_RenderStateAlphaTestState == Kore::Graphics4::RenderState::AlphaTestState,
  "Kore::Graphics4::RenderState::AlphaTestState enum value changed.");
static_assert(
  WE_RenderStateAlphaReferenceState == Kore::Graphics4::RenderState::AlphaReferenceState,
  "Kore::Graphics4::RenderState::AlphaReferenceState enum value changed.");
static_assert(
  WE_RenderStateConservativeRasterization == Kore::Graphics4::RenderState::ConservativeRasterization,
  "Kore::Graphics4::RenderState::ConservativeRasterization enum value changed.");

// Kore::Graphics4::BlendingOperation assertions
static_assert(
  WE_BlendingOperationBlendOne == Kore::Graphics4::BlendingOperation::BlendOne,
  "Kore::Graphics4::BlendingOperation::BlendOne enum value changed.");
static_assert(
  WE_BlendingOperationBlendZero == Kore::Graphics4::BlendingOperation::BlendZero,
  "Kore::Graphics4::BlendingOperation::BlendZero enum value changed.");
static_assert(
  WE_BlendingOperationSourceAlpha == Kore::Graphics4::BlendingOperation::SourceAlpha,
  "Kore::Graphics4::BlendingOperation::SourceAlpha enum value changed.");
static_assert(
  WE_BlendingOperationDestinationAlpha == Kore::Graphics4::BlendingOperation::DestinationAlpha,
  "Kore::Graphics4::BlendingOperation::DestinationAlpha enum value changed.");
static_assert(
  WE_BlendingOperationInverseSourceAlpha == Kore::Graphics4::BlendingOperation::InverseSourceAlpha,
  "Kore::Graphics4::BlendingOperation::InverseSourceAlpha enum value changed.");
static_assert(
  WE_BlendingOperationInverseDestinationAlpha == Kore::Graphics4::BlendingOperation::InverseDestinationAlpha,
  "Kore::Graphics4::BlendingOperation::InverseDestinationAlpha enum value changed.");
static_assert(
  WE_BlendingOperationSourceColor == Kore::Graphics4::BlendingOperation::SourceColor,
  "Kore::Graphics4::BlendingOperation::SourceColor enum value changed.");
static_assert(
  WE_BlendingOperationDestinationColor == Kore::Graphics4::BlendingOperation::DestinationColor,
  "Kore::Graphics4::BlendingOperation::DestinationColor enum value changed.");
static_assert(
  WE_BlendingOperationInverseSourceColor == Kore::Graphics4::BlendingOperation::InverseSourceColor,
  "Kore::Graphics4::BlendingOperation::InverseSourceColor enum value changed.");
static_assert(
  WE_BlendingOperationInverseDestinationColor == Kore::Graphics4::BlendingOperation::InverseDestinationColor,
  "Kore::Graphics4::BlendingOperation::InverseDestinationColor enum value changed.");

// Kore::Graphics4::ZCompareMode assertions
static_assert(
  WE_ZCompareModeZCompareAlways == Kore::Graphics4::ZCompareMode::ZCompareAlways,
  "Kore::Graphics4::ZCompareMode::ZCompareAlways enum value changed.");
static_assert(
  WE_ZCompareModeZCompareNever == Kore::Graphics4::ZCompareMode::ZCompareNever,
  "Kore::Graphics4::ZCompareMode::ZCompareNever enum value changed.");
static_assert(
  WE_ZCompareModeZCompareEqual == Kore::Graphics4::ZCompareMode::ZCompareEqual,
  "Kore::Graphics4::ZCompareMode::ZCompareEqual enum value changed.");
static_assert(
  WE_ZCompareModeZCompareNotEqual == Kore::Graphics4::ZCompareMode::ZCompareNotEqual,
  "Kore::Graphics4::ZCompareMode::ZCompareNotEqual enum value changed.");
static_assert(
  WE_ZCompareModeZCompareLess == Kore::Graphics4::ZCompareMode::ZCompareLess,
  "Kore::Graphics4::ZCompareMode::ZCompareLess enum value changed.");
static_assert(
  WE_ZCompareModeZCompareLessEqual == Kore::Graphics4::ZCompareMode::ZCompareLessEqual,
  "Kore::Graphics4::ZCompareMode::ZCompareLessEqual enum value changed.");
static_assert(
  WE_ZCompareModeZCompareGreater == Kore::Graphics4::ZCompareMode::ZCompareGreater,
  "Kore::Graphics4::ZCompareMode::ZCompareGreater enum value changed.");
static_assert(
  WE_ZCompareModeZCompareGreaterEqual == Kore::Graphics4::ZCompareMode::ZCompareGreaterEqual,
  "Kore::Graphics4::ZCompareMode::ZCompareGreaterEqual enum value changed.");

// Kore::Graphics4::CullMode assertions
static_assert(
  WE_CullModeClockwise == Kore::Graphics4::CullMode::Clockwise,
  "Kore::Graphics4::CullMode::Clockwise enum value changed.");
static_assert(
  WE_CullModeCounterClockwise == Kore::Graphics4::CullMode::CounterClockwise,
  "Kore::Graphics4::CullMode::CounterClockwise enum value changed.");
static_assert(
  WE_CullModeNoCulling == Kore::Graphics4::CullMode::NoCulling,
  "Kore::Graphics4::CullMode::NoCulling enum value changed.");

// Kore::Graphics4::TexDir assertions
static_assert(
  WE_TexDirU == Kore::Graphics4::TexDir::U,
  "Kore::Graphics4::TexDir::U enum value changed.");
static_assert(
  WE_TexDirV == Kore::Graphics4::TexDir::V,
  "Kore::Graphics4::TexDir::V enum value changed.");
static_assert(
  WE_TexDirW == Kore::Graphics4::TexDir::W,
  "Kore::Graphics4::TexDir::W enum value changed.");

// Kore::Graphics4::FogType assertions
static_assert(
  WE_FogTypeLinearFog == Kore::Graphics4::FogType::LinearFog,
  "Kore::Graphics4::FogType::LinearFog enum value changed.");

// Kore::Graphics4::RenderTargetFormat assertions
static_assert(
  WE_RenderTargetFormatTarget32Bit == Kore::Graphics4::RenderTargetFormat::Target32Bit,
  "Kore::Graphics4::RenderTargetFormat::Target32Bit enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget64BitFloat == Kore::Graphics4::RenderTargetFormat::Target64BitFloat,
  "Kore::Graphics4::RenderTargetFormat::Target64BitFloat enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget32BitRedFloat == Kore::Graphics4::RenderTargetFormat::Target32BitRedFloat,
  "Kore::Graphics4::RenderTargetFormat::Target32BitRedFloat enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget128BitFloat == Kore::Graphics4::RenderTargetFormat::Target128BitFloat,
  "Kore::Graphics4::RenderTargetFormat::Target128BiTarget128BitFloattFloat enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget16BitDepth == Kore::Graphics4::RenderTargetFormat::Target16BitDepth,
  "Kore::Graphics4::RenderTargetFormat::Target16BitDepth enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget8BitRed == Kore::Graphics4::RenderTargetFormat::Target8BitRed,
  "Kore::Graphics4::RenderTargetFormat::Target8BitRed enum value changed.");
static_assert(
  WE_RenderTargetFormatTarget16BitRedFloat == Kore::Graphics4::RenderTargetFormat::Target16BitRedFloat,
  "Kore::Graphics4::RenderTargetFormat::Target16BitRedFloat enum value changed.");

// Kore::Graphics4::StencilAction assertions
static_assert(
  WE_StencilActionKeep == Kore::Graphics4::StencilAction::Keep,
  "Kore::Graphics4::StencilAction::Keep enum value changed.");
static_assert(
  WE_StencilActionZero == Kore::Graphics4::StencilAction::Zero,
  "Kore::Graphics4::StencilAction::Zero enum value changed.");
static_assert(
  WE_StencilActionReplace == Kore::Graphics4::StencilAction::Replace,
  "Kore::Graphics4::StencilAction::Replace enum value changed.");
static_assert(
  WE_StencilActionIncrement == Kore::Graphics4::StencilAction::Increment,
  "Kore::Graphics4::StencilAction::Increment enum value changed.");
static_assert(
  WE_StencilActionIncrementWrap == Kore::Graphics4::StencilAction::IncrementWrap,
  "Kore::Graphics4::StencilAction::IncrementWrap enum value changed.");
static_assert(
  WE_StencilActionDecrement == Kore::Graphics4::StencilAction::Decrement,
  "Kore::Graphics4::StencilAction::Decrement enum value changed.");
static_assert(
  WE_StencilActionDecrementWrap == Kore::Graphics4::StencilAction::DecrementWrap,
  "Kore::Graphics4::StencilAction::DecrementWrap enum value changed.");
static_assert(
  WE_StencilActionInvert == Kore::Graphics4::StencilAction::Invert,
  "Kore::Graphics4::StencilAction::Invert enum value changed.");

// Kore::Graphics4::TextureOperation assertions
static_assert(
  WE_TextureOperationModulateOperation == Kore::Graphics4::TextureOperation::ModulateOperation,
  "Kore::Graphics4::TextureOperation::ModulateOperation enum value changed.");
static_assert(
  WE_TextureOperationSelectFirstOperation == Kore::Graphics4::TextureOperation::SelectFirstOperation,
  "Kore::Graphics4::TextureOperation::SelectFirstOperation enum value changed.");
static_assert(
  WE_TextureOperationSelectSecondOperation == Kore::Graphics4::TextureOperation::SelectSecondOperation,
  "Kore::Graphics4::TextureOperation::SelectSecondOperation enum value changed.");

// Kore::Graphics4::TextureArgument assertions
static_assert(
  WE_TextureArgumentCurrentColorArgument == Kore::Graphics4::TextureArgument::CurrentColorArgument,
  "Kore::Graphics4::TextureArgument::CurrentColorArgument enum value changed.");
static_assert(
  WE_TextureArgumentTextureColorArgument == Kore::Graphics4::TextureArgument::TextureColorArgument,
  "Kore::Graphics4::TextureArgument::TextureColorArgument enum value changed.");


/* Kore::Graphics4::VertexBuffer */

// .. constructors
// TODO: How to pass const VertexStructure& structure?
WC_Kore_Graphics4_VertexBuffer* Kore_Graphics4_VertexBuffer_create(
	int count, const VertexStructure& structure, int instanceDataStepRate);

// .. destructor
void Kore_Graphics4_VertexBuffer_destroy(WC_Kore_Graphics4_VertexBuffer* self);

// .. methods
float* Kore_Graphics4_VertexBuffer_lock(WC_Kore_Graphics4_VertexBuffer* self);
float* Kore_Graphics4_VertexBuffer_lockSC(
	WC_Kore_Graphics4_VertexBuffer* self,
	int start, int count);
void Kore_Graphics4_VertexBuffer_unlock(WC_Kore_Graphics4_VertexBuffer* self);
int Kore_Graphics4_VertexBuffer_count(WC_Kore_Graphics4_VertexBuffer* self);
int Kore_Graphics4_VertexBuffer_stride(WC_Kore_Graphics4_VertexBuffer* self);

/* Kore::Graphics4::IndexBuffer */

// .. constructors
WC_Kore_Graphics4_IndexBuffer* Kore_Graphics4_IndexBuffer_create(int count);

// .. destructor
void Kore_Graphics4_IndexBuffer_destroy(WC_Kore_Graphics4_IndexBuffer* self);

// .. methods
int* Kore_Graphics4_IndexBuffer_lock(WC_Kore_Graphics4_IndexBuffer* self);
void Kore_Graphics4_IndexBuffer_unlock(WC_Kore_Graphics4_IndexBuffer* self);
int Kore_Graphics4_IndexBuffer_count(WC_Kore_Graphics4_IndexBuffer* self);

/* Kore::Graphics4::RenderTarget */

// .. constructors
WC_Kore_Graphics4_RenderTarget* Kore_Graphics4_RenderTarget_createWHDAFSC(
	int width, int height, int depthBufferBits, bool antialiasing,
	WE_Kore_Graphics4_RenderTargetFormat format,
	int stencilBufferBits, int contextId);
WC_Kore_Graphics4_RenderTarget* Kore_Graphics4_RenderTarget_createCDAFSC(
	int cubeMapSize, int depthBufferBits, bool antialiasing,
	WE_Kore_Graphics4_RenderTargetFormat format,
	int stencilBufferBits, int contextId);

// .. destructor
void Kore_Graphics4_RenderTarget_destroy(WC_Kore_Graphics4_RenderTarget* self);

// .. methods
// TODO: How to pass unit by value?
void Kore_Graphics4_RenderTarget_useColorAsTexture(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_TextureUnit* unit);
// TODO: How to pass unit by value?
void Kore_Graphics4_RenderTarget_useDepthAsTexture(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_TextureUnit* unit);
void Kore_Graphics4_RenderTarget_setDepthStencilFrom(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_RenderTarget* source);
void Kore_Graphics4_RenderTarget_getPixels(
	WC_Kore_Graphics4_RenderTarget* self, u8* data);

// .. data accessors, TODO: Setter needed?
int Kore_Graphics4_RenderTarget_getWidth(WC_Kore_Graphics4_RenderTarget* self);
int Kore_Graphics4_RenderTarget_getHeight(WC_Kore_Graphics4_RenderTarget* self);
int Kore_Graphics4_RenderTarget_getTexWidth(
	WC_Kore_Graphics4_RenderTarget* self);
int Kore_Graphics4_RenderTarget_getTexHeight(
	WC_Kore_Graphics4_RenderTarget* self);
int Kore_Graphics4_RenderTarget_getContextId(
	WC_Kore_Graphics4_RenderTarget* self);
bool Kore_Graphics4_RenderTarget_getIsCubeMap(
	WC_Kore_Graphics4_RenderTarget* self);
bool Kore_Graphics4_RenderTarget_getIsDepthAttachment(
	WC_Kore_Graphics4_RenderTarget* self);

/* Functions */

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
