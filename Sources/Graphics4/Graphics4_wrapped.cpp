#include <Kore/pch.h>
#include <Kore/System.h>
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics4/PipelineState.h>
#include <Kore/Graphics4/Shader.h>
#include <Kore/Graphics4/Texture.h>
#include <Kore/Graphics4/VertexStructure.h>

#include <assert.h>

#include "../CWrapper.h"
// #include "../Helpers.h"

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
WC_Kore_Graphics4_VertexBuffer* Kore_Graphics4_VertexBuffer_create(
	int count, WC_Kore_Graphics4_VertexStructure* structure,
	int instanceDataStepRate) {
	return reinterpret_cast<WC_Kore_Graphics4_VertexBuffer*>(
		new Kore::Graphics4::VertexBuffer(
			count,
			*reinterpret_cast<Kore::Graphics4::VertexStructure*>(structure),
			instanceDataStepRate));
}

// .. destructor
void Kore_Graphics4_VertexBuffer_destroy(WC_Kore_Graphics4_VertexBuffer* self) {
	delete reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self);
}

// .. methods
float* Kore_Graphics4_VertexBuffer_lock(WC_Kore_Graphics4_VertexBuffer* self) {
	return reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self)->lock();
}

float* Kore_Graphics4_VertexBuffer_lockSC(
	WC_Kore_Graphics4_VertexBuffer* self,
	int start, int count) {
	return reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self)->lock(
		start, count);
}

void Kore_Graphics4_VertexBuffer_unlock(WC_Kore_Graphics4_VertexBuffer* self) {
	reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self)->unlock();
}

int Kore_Graphics4_VertexBuffer_count(WC_Kore_Graphics4_VertexBuffer* self) {
	return reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self)->count();
}

int Kore_Graphics4_VertexBuffer_stride(WC_Kore_Graphics4_VertexBuffer* self) {
	return reinterpret_cast<Kore::Graphics4::VertexBuffer*>(self)->stride();
}

/* Kore::Graphics4::IndexBuffer */

// .. constructors
WC_Kore_Graphics4_IndexBuffer* Kore_Graphics4_IndexBuffer_create(int count) {
	return reinterpret_cast<WC_Kore_Graphics4_IndexBuffer*>(
		new Kore::Graphics4::IndexBuffer(count));
}

// .. destructor
void Kore_Graphics4_IndexBuffer_destroy(WC_Kore_Graphics4_IndexBuffer* self) {
	delete reinterpret_cast<Kore::Graphics4::IndexBuffer*>(self);
}

// .. methods
int* Kore_Graphics4_IndexBuffer_lock(WC_Kore_Graphics4_IndexBuffer* self) {
	return reinterpret_cast<Kore::Graphics4::IndexBuffer*>(self)->lock();
}

void Kore_Graphics4_IndexBuffer_unlock(WC_Kore_Graphics4_IndexBuffer* self) {
	reinterpret_cast<Kore::Graphics4::IndexBuffer*>(self)->unlock();
}

int Kore_Graphics4_IndexBuffer_count(WC_Kore_Graphics4_IndexBuffer* self) {
	return reinterpret_cast<Kore::Graphics4::IndexBuffer*>(self)->count();
}

/* Kore::Graphics4::RenderTarget */

// .. constructors
WC_Kore_Graphics4_RenderTarget* Kore_Graphics4_RenderTarget_createWHDAFSC(
	int width, int height, int depthBufferBits, bool antialiasing,
	WE_Kore_Graphics4_RenderTargetFormat format,
	int stencilBufferBits, int contextId) {
	return reinterpret_cast<WC_Kore_Graphics4_RenderTarget*>(
		new Kore::Graphics4::RenderTarget(
			width, height, depthBufferBits, antialiasing,
			(Kore::Graphics4::RenderTargetFormat)format,
			stencilBufferBits, contextId));
}

WC_Kore_Graphics4_RenderTarget* Kore_Graphics4_RenderTarget_createCDAFSC(
	int cubeMapSize, int depthBufferBits, bool antialiasing,
	WE_Kore_Graphics4_RenderTargetFormat format,
	int stencilBufferBits, int contextId) {
	return reinterpret_cast<WC_Kore_Graphics4_RenderTarget*>(
		new Kore::Graphics4::RenderTarget(
			cubeMapSize, depthBufferBits, antialiasing,
			(Kore::Graphics4::RenderTargetFormat)format,
			stencilBufferBits, contextId));
}

// .. destructor
void Kore_Graphics4_RenderTarget_destroy(WC_Kore_Graphics4_RenderTarget* self) {
	delete reinterpret_cast<Kore::Graphics4::RenderTarget*>(self);
}

// .. methods
void Kore_Graphics4_RenderTarget_useColorAsTexture(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_TextureUnit* unit) {
	reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->useColorAsTexture(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit));
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit);
}

void Kore_Graphics4_RenderTarget_useDepthAsTexture(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_TextureUnit* unit) {
	reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->useDepthAsTexture(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit));
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit);
}

void Kore_Graphics4_RenderTarget_setDepthStencilFrom(
	WC_Kore_Graphics4_RenderTarget* self,
	WC_Kore_Graphics4_RenderTarget* source) {
	reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->setDepthStencilFrom(
		reinterpret_cast<Kore::Graphics4::RenderTarget*>(source));
}

void Kore_Graphics4_RenderTarget_getPixels(
	WC_Kore_Graphics4_RenderTarget* self, u8* data) {
	reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->getPixels(data);
}

// .. data accessors, TODO: Setter needed?
int Kore_Graphics4_RenderTarget_getWidth(WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->width;
}

int Kore_Graphics4_RenderTarget_getHeight(WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->height;
}

int Kore_Graphics4_RenderTarget_getTexWidth(
	WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->texWidth;
}

int Kore_Graphics4_RenderTarget_getTexHeight(
	WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->texHeight;
}

int Kore_Graphics4_RenderTarget_getContextId(
	WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->contextId;
}

bool Kore_Graphics4_RenderTarget_getIsCubeMap(
	WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->isCubeMap;
}

bool Kore_Graphics4_RenderTarget_getIsDepthAttachment(
	WC_Kore_Graphics4_RenderTarget* self) {
	return reinterpret_cast<Kore::Graphics4::RenderTarget*>(self)->isDepthAttachment;
}

/* Kore::Graphics4 Functions */

void Kore_Graphics4_setBool(
	WC_Kore_Graphics4_ConstantLocation* location, bool value) {
	Kore::Graphics4::setBool(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
}

void Kore_Graphics4_setInt(
	WC_Kore_Graphics4_ConstantLocation* location, int value) {
	Kore::Graphics4::setInt(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
}

void Kore_Graphics4_setFloat(
	WC_Kore_Graphics4_ConstantLocation* location, float value) {
	Kore::Graphics4::setFloat(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
}

void Kore_Graphics4_setFloat2(
	WC_Kore_Graphics4_ConstantLocation* location, float value1, float value2) {
	Kore::Graphics4::setFloat2(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location),
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location,
		value1, value2);
}

// TODO:
// void Kore_Graphics4_setFloat2Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec2 value) {
// 	Kore::Graphics4::setFloat2(
// 		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
// 		//reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
// }

void Kore_Graphics4_setFloat3(
	WC_Kore_Graphics4_ConstantLocation* location,
	float value1, float value2, float value3) {
	Kore::Graphics4::setFloat3(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location),
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location,
		value1, value2, value3);
}

// TODO:
// void Kore_Graphics4_setFloat3Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec3 value) {
// 	Kore::Graphics4::setFloat3(
// 		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
//		//reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
// }

void Kore_Graphics4_setFloat4(
	WC_Kore_Graphics4_ConstantLocation* location,
	float value1, float value2, float value3, float value4) {
	Kore::Graphics4::setFloat4(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location),
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location,
		value1, value2, value3, value4);
}

// TODO:
// void Kore_Graphics4_setFloat4Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec4 value) {
// 	Kore::Graphics4::setFloat4(
// 		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), value);
// 		//reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, value);
// }

void Kore_Graphics4_setFloats(
	WC_Kore_Graphics4_ConstantLocation* location, float* floats, int count) {
	Kore::Graphics4::setFloats(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location),
		// reinterpret_cast<KoreC::WConstantLocation4*>(location)->location,
		floats, count);
}

// TODO:
// void Kore_Graphics4_setMatrix3(
// 	WC_Kore_Graphics4_ConstantLocation* location, mat3* value) {
// 	Kore::Graphics4::setMatrix(
// 		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), *value);
// 		//reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, *value);
// }
void Kore_Graphics4_setMatrix3FromElements(
	WC_Kore_Graphics4_ConstantLocation* location,
	KC_Mat3ElementsHelper* mat3Elements) {
	Kore::mat3 m;
	m.Set(0, 0, mat3Elements->e00); m.Set(0, 1, mat3Elements->e10); m.Set(0, 2, mat3Elements->e20);
	m.Set(1, 0, mat3Elements->e01); m.Set(1, 1, mat3Elements->e11); m.Set(1, 2, mat3Elements->e21);
	m.Set(2, 0, mat3Elements->e02); m.Set(2, 1, mat3Elements->e12); m.Set(2, 2, mat3Elements->e22);
	Kore:: Graphics4::setMatrix(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), m);
}

// TODO:
// void Kore_Graphics4_setMatrix4(
// 	WC_Kore_Graphics4_ConstantLocation* location, mat4* value) {
// 	Kore::Graphics4::setMatrix(
// 		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), *value);
// 		//reinterpret_cast<KoreC::WConstantLocation4*>(location)->location, *value);
// }
void Kore_Graphics4_setMatrix4FromElements(
	WC_Kore_Graphics4_ConstantLocation* location,
	KC_Mat4ElementsHelper* mat4Elements) {
	Kore::mat4 m;
	m.Set(0, 0, mat4Elements->e00); m.Set(0, 1, mat4Elements->e10); m.Set(0, 2, mat4Elements->e20); m.Set(0, 3, mat4Elements->e30);
	m.Set(1, 0, mat4Elements->e01); m.Set(1, 1, mat4Elements->e11); m.Set(1, 2, mat4Elements->e21); m.Set(1, 3, mat4Elements->e31);
	m.Set(2, 0, mat4Elements->e02); m.Set(2, 1, mat4Elements->e12); m.Set(2, 2, mat4Elements->e22); m.Set(2, 3, mat4Elements->e32);
	m.Set(3, 0, mat4Elements->e03); m.Set(3, 1, mat4Elements->e13); m.Set(3, 2, mat4Elements->e23); m.Set(3, 3, mat4Elements->e33);
	Kore:: Graphics4::setMatrix(
		*reinterpret_cast<Kore::Graphics4::ConstantLocation*>(location), m);
}

void Kore_Graphics4_setVertexBuffer(
	WC_Kore_Graphics4_VertexBuffer* vertexBuffer) {
	Kore::Graphics4::setVertexBuffer(
		*reinterpret_cast<Kore::Graphics4::VertexBuffer*>(vertexBuffer));
}

void Kore_Graphics4_setVertexBuffers(
	WC_Kore_Graphics4_VertexBuffer** vertexBuffers, int count) {
	Kore::Graphics4::setVertexBuffers(
		reinterpret_cast<Kore::Graphics4::VertexBuffer**>(vertexBuffers), count);
}

void Kore_Graphics4_setIndexBuffer(
	WC_Kore_Graphics4_IndexBuffer* indexBuffer) {
	Kore::Graphics4::setIndexBuffer(
		*reinterpret_cast<Kore::Graphics4::IndexBuffer*>(indexBuffer));
}

void Kore_Graphics4_setTexture(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_Texture* texture) {
	Kore::Graphics4::setTexture(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit,
		reinterpret_cast<Kore::Graphics4::Texture*>(texture));
}

void Kore_Graphics4_setTextureArray(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_TextureArray* array) {
	Kore::Graphics4::setTextureArray(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit,
		reinterpret_cast<Kore::Graphics4::TextureArray*>(array));
}

void Kore_Graphics4_setImageTexture(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_Texture* texture) {
	Kore::Graphics4::setImageTexture(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit,
		reinterpret_cast<Kore::Graphics4::Texture*>(texture));
}

void Kore_Graphics4_setPipeline(WC_Kore_Graphics4_PipelineState* pipeline) {
	Kore::Graphics4::setPipeline(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(pipeline));
}


void Kore_Graphics4_drawIndexedVertices() {
	Kore::Graphics4::drawIndexedVertices();
}

void Kore_Graphics4_drawIndexedVerticesSC(
	int start, int count) {
	Kore::Graphics4::drawIndexedVertices(start, count);
}

void Kore_Graphics4_drawIndexedVerticesInstancedI(
	int instanceCount) {
	Kore::Graphics4::drawIndexedVerticesInstanced(instanceCount);
}

void Kore_Graphics4_drawIndexedVerticesInstancedISC(
	int instanceCount, int start, int count) {
	Kore::Graphics4::drawIndexedVerticesInstanced(instanceCount, start, count);
}


void Kore_Graphics4_changeResolution(int width, int height) {
	Kore::Graphics4::changeResolution(width, height);
}

bool Kore_Graphics4_hasWindow() {
	Kore::Graphics4::hasWindow();
}

void Kore_Graphics4_setWindow(bool value) {
	Kore::Graphics4::setWindow(value);
}

int Kore_Graphics4_antialiasingSamples() {
	return Kore::Graphics4::antialiasingSamples();
}

void Kore_Graphics4_setAntialiasingSamples(int samples) {
	Kore::Graphics4::setAntialiasingSamples(samples);
}


bool Kore_Graphics4_renderTargetsInvertedY() {
	Kore::Graphics4::renderTargetsInvertedY();
}

void Kore_Graphics4_setRenderTargets(
	WC_Kore_Graphics4_RenderTarget** targets, int count) {
	Kore::Graphics4::setRenderTargets(
		reinterpret_cast<Kore::Graphics4::RenderTarget**>(targets), count);
}

void Kore_Graphics4_setRenderTarget(WC_Kore_Graphics4_RenderTarget* target) {
	Kore::Graphics4::setRenderTarget(
		reinterpret_cast<Kore::Graphics4::RenderTarget*>(target));
}

void Kore_Graphics4_setRenderTargetFace(
	WC_Kore_Graphics4_RenderTarget* texture, int face) {
	Kore::Graphics4::setRenderTargetFace(
		reinterpret_cast<Kore::Graphics4::RenderTarget*>(texture), face);
}

void Kore_Graphics4_restoreRenderTarget() {
	Kore::Graphics4::restoreRenderTarget();
}


void Kore_Graphics4_setup() {
	Kore::Graphics4::setup();
}

bool Kore_Graphics4_swapBuffers(int windowId) {
  Kore::Graphics4::swapBuffers(windowId);
}

void Kore_Graphics4_begin(int windowId) {
  Kore::Graphics4::begin(windowId);
}

void Kore_Graphics4_end(int windowId) {
  Kore::Graphics4::end(windowId);
}

void Kore_Graphics4_makeCurrent(int windowId) {
	// Kore::Graphics4::makeCurrent(windowId);
	Kore::System::makeCurrent(windowId);
}

void Kore_Graphics4_clearCurrent() {
	Kore::Graphics4::clearCurrent();
}


void Kore_Graphics4_viewport(int x, int y, int width, int height) {
	Kore::Graphics4::viewport(x, y, width, height);
}

void Kore_Graphics4_scissor(int x, int y, int width, int height) {
	Kore::Graphics4::scissor(x, y, width, height);
}

void Kore_Graphics4_disableScissor() {
	Kore::Graphics4::disableScissor();
}


void Kore_Graphics4_setTextureAddressing(
	WC_Kore_Graphics4_TextureUnit* unit,
	WE_Kore_Graphics4_TexDir dir,
	WE_Kore_Graphics4_TextureAddressing addressing) {
	Kore::Graphics4::setTextureAddressing(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit,
		(Kore::Graphics4::TexDir)dir,
		(Kore::Graphics4::TextureAddressing)addressing);
}

void Kore_Graphics4_setTextureMagnificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter) {
	Kore::Graphics4::setTextureMagnificationFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::TextureFilter)filter);
}

void Kore_Graphics4_setTextureMinificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter) {
	Kore::Graphics4::setTextureMinificationFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::TextureFilter)filter);
}

void Kore_Graphics4_setTextureMipmapFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_MipmapFilter filter) {
	Kore::Graphics4::setTextureMipmapFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::MipmapFilter)filter);
}

void Kore_Graphics4_setTexture3DAddressing(
	WC_Kore_Graphics4_TextureUnit* unit,
	WE_Kore_Graphics4_TexDir dir,
	WE_Kore_Graphics4_TextureAddressing addressing) {
	Kore::Graphics4::setTexture3DAddressing(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(unit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(unit)->unit,
		(Kore::Graphics4::TexDir)dir,
		(Kore::Graphics4::TextureAddressing)addressing);
}

void Kore_Graphics4_setTexture3DMagnificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter) {
	Kore::Graphics4::setTexture3DMagnificationFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::TextureFilter)filter);
}

void Kore_Graphics4_setTexture3DMinificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter) {
	Kore::Graphics4::setTexture3DMinificationFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::TextureFilter)filter);
}

void Kore_Graphics4_setTexture3DMipmapFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_MipmapFilter filter) {
	Kore::Graphics4::setTexture3DMipmapFilter(
		*reinterpret_cast<Kore::Graphics4::TextureUnit*>(texunit),
		// reinterpret_cast<KoreC::WTextureUnit4*>(texunit)->unit,
		(Kore::Graphics4::MipmapFilter)filter);
}

void Kore_Graphics4_setTextureOperation(
	WE_Kore_Graphics4_TextureOperation operation,
	WE_Kore_Graphics4_TextureArgument arg1,
	WE_Kore_Graphics4_TextureArgument arg2) {
	Kore::Graphics4::setTextureOperation(
		(Kore::Graphics4::TextureOperation)operation,
		(Kore::Graphics4::TextureArgument)arg1,
		(Kore::Graphics4::TextureArgument)arg2);
}


bool Kore_Graphics4_vsynced() {
	return Kore::Graphics4::vsynced();
}

unsigned Kore_Graphics4_refreshRate() {
	return Kore::Graphics4::refreshRate();
}

bool Kore_Graphics4_nonPow2TexturesSupported() {
	return Kore::Graphics4::nonPow2TexturesSupported();
}


bool Kore_Graphics4_initOcclusionQuery(uint* occlusionQuery) {
	return Kore::Graphics4::initOcclusionQuery(occlusionQuery);
}

void Kore_Graphics4_deleteOcclusionQuery(uint occlusionQuery) {
	Kore::Graphics4::deleteOcclusionQuery(occlusionQuery);
}

void Kore_Graphics4_renderOcclusionQuery(uint occlusionQuery, int triangles) {
	Kore::Graphics4::renderOcclusionQuery(occlusionQuery, triangles);
}

bool Kore_Graphics4_isQueryResultsAvailable(uint occlusionQuery) {
	return Kore::Graphics4::isQueryResultsAvailable(occlusionQuery);
}

void Kore_Graphics4_getQueryResults(uint occlusionQuery, uint* pixelCount) {
	Kore::Graphics4::getQueryResults(occlusionQuery, pixelCount);
}


void Kore_Graphics4_clear(uint flags, uint color, float depth, int stencil) {
  Kore::Graphics4::clear(flags, color, depth, stencil);
}

void Kore_Graphics4_init(
	int windowId, int depthBufferBits, int stencilBufferBits, bool vsync) {
	Kore::Graphics4::init(windowId, depthBufferBits, stencilBufferBits, vsync);
}

void Kore_Graphics4_destroy(int windowId) {
	Kore::Graphics4::destroy(windowId);
}

bool Kore_Graphics4_getFullscreen() {
	return Kore::Graphics4::fullscreen;
}

void Kore_Graphics4_flush() {
	Kore::Graphics4::flush();
}

#ifdef __cplusplus
}
#endif
