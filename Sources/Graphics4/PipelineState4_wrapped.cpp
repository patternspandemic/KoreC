#include <Kore/pch.h>
#include <Kore/Graphics4/Graphics.h>
#include <Kore/Graphics4/Shader.h>
#include <Kore/Graphics4/VertexStructure.h>
#include <Kore/Graphics4/PipelineState.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Kore::Graphics4::PipelineState */

// .. constructors
WC_Kore_Graphics4_PipelineState* Kore_Graphics4_PipelineState_create() {
  return reinterpret_cast<WC_Kore_Graphics4_PipelineState*>(
		new Kore::Graphics4::PipelineState());
}

// .. destructor
void Kore_Graphics4_PipelineState_destroy(
	WC_Kore_Graphics4_PipelineState* self) {
  delete reinterpret_cast<Kore::Graphics4::PipelineState*>(self);
}

// .. methods
void Kore_Graphics4_PipelineState_compile(
	WC_Kore_Graphics4_PipelineState* self) {
  reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->compile();
}

// Must copy value object to heap in order to wrap in opaque C struct
WC_Kore_Graphics4_ConstantLocation* Kore_Graphics4_PipelineState_getConstantLocation(
	WC_Kore_Graphics4_PipelineState* self, const char* name) {
	return reinterpret_cast<WC_Kore_Graphics4_ConstantLocation*>(
		new Kore::Graphics4::ConstantLocation(
			reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->getConstantLocation(name)
		)
	);
}

// Must copy value object to heap in order to wrap in opaque C struct
WC_Kore_Graphics4_TextureUnit* Kore_Graphics4_PipelineState_getTextureUnit(
	WC_Kore_Graphics4_PipelineState* self, const char* name) {
	return reinterpret_cast<WC_Kore_Graphics4_TextureUnit*>(
		new Kore::Graphics4::TextureUnit(
			reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->getTextureUnit(name)
		)
	);
}

void Kore_Graphics4_PipelineState_setInputLayoutAt(
	WC_Kore_Graphics4_PipelineState* self, int index,
	WC_Kore_Graphics4_VertexStructure* vertexStructure) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->inputLayout[index] = reinterpret_cast<Kore::Graphics4::VertexStructure*>(vertexStructure);
}

// .. data accessors
// TODO: Verify WC_Kore_Graphics4_VertexStructure** return
WC_Kore_Graphics4_VertexStructure** Kore_Graphics4_PipelineState_getInputLayout(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_VertexStructure**>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->inputLayout);
}

WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getVertexShader(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->vertexShader);
}

void Kore_Graphics4_PipelineState_setVertexShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->vertexShader = reinterpret_cast<Kore::Graphics4::Shader*>(shader);
}

WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getFragmentShader(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->fragmentShader);
}

void Kore_Graphics4_PipelineState_setFragmentShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->fragmentShader = reinterpret_cast<Kore::Graphics4::Shader*>(shader);
}

WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getGeometryShader(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->geometryShader);
}

void Kore_Graphics4_PipelineState_setGeometryShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->geometryShader = reinterpret_cast<Kore::Graphics4::Shader*>(shader);
}

WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getTessellationControlShader(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->tessellationControlShader);
}

void Kore_Graphics4_PipelineState_setTessellationControlShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->tessellationControlShader = reinterpret_cast<Kore::Graphics4::Shader*>(shader);
}

WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getTessellationEvaluationShader(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->tessellationEvaluationShader);
}

void Kore_Graphics4_PipelineState_setTessellationEvaluationShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->tessellationEvaluationShader = reinterpret_cast<Kore::Graphics4::Shader*>(shader);
}

WE_Kore_Graphics4_CullMode Kore_Graphics4_PipelineState_getCullMode(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_CullMode)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->cullMode;
}

void Kore_Graphics4_PipelineState_setCullMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_CullMode mode) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->cullMode = (Kore::Graphics4::CullMode)mode;
}

bool Kore_Graphics4_PipelineState_getDepthWrite(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->depthWrite;
}

void Kore_Graphics4_PipelineState_setDepthWrite(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->depthWrite = value;
}

WE_Kore_Graphics4_ZCompareMode Kore_Graphics4_PipelineState_getDepthMode(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_ZCompareMode)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->depthMode;
}

void Kore_Graphics4_PipelineState_setDepthMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_ZCompareMode mode) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->depthMode = (Kore::Graphics4::ZCompareMode)mode;
}

WE_Kore_Graphics4_ZCompareMode Kore_Graphics4_PipelineState_getStencilMode(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_ZCompareMode)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilMode;
}

void Kore_Graphics4_PipelineState_setStencilMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_ZCompareMode mode) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilMode = (Kore::Graphics4::ZCompareMode)mode;
}

WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilBothPass(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_StencilAction)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilBothPass;
}

void Kore_Graphics4_PipelineState_setStencilBothPass(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilBothPass = (Kore::Graphics4::StencilAction)action;
}

WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilDepthFail(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_StencilAction)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilDepthFail;
}

void Kore_Graphics4_PipelineState_setStencilDepthFail(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilDepthFail = (Kore::Graphics4::StencilAction)action;
}

WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilFail(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_StencilAction)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilFail;
}

void Kore_Graphics4_PipelineState_setStencilFail(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilFail = (Kore::Graphics4::StencilAction)action;
}

int Kore_Graphics4_PipelineState_getStencilReferenceValue(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilReferenceValue;
}

void Kore_Graphics4_PipelineState_setStencilReferenceValue(
	WC_Kore_Graphics4_PipelineState* self,
	int value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilReferenceValue = value;
}

int Kore_Graphics4_PipelineState_getStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilReadMask;
}

void Kore_Graphics4_PipelineState_setStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self,
	int value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilReadMask = value;
}

int Kore_Graphics4_PipelineState_getStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilWriteMask;
}

void Kore_Graphics4_PipelineState_setStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self,
	int value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->stencilWriteMask = value;
}

// TODO: One, Zero deactivates blending, add convenience funcs
WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getBlendSource(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_BlendingOperation)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->blendSource;
}

void Kore_Graphics4_PipelineState_setBlendSource(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->blendSource = (Kore::Graphics4::BlendingOperation)operation;
}

WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getBlendDestination(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_BlendingOperation)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->blendDestination;
}

void Kore_Graphics4_PipelineState_setBlendDestination(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->blendDestination = (Kore::Graphics4::BlendingOperation)operation;
}

WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getAlphaBlendSource(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_BlendingOperation)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->alphaBlendSource;
}

void Kore_Graphics4_PipelineState_setAlphaBlendSource(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->alphaBlendSource = (Kore::Graphics4::BlendingOperation)operation;
}

WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getAlphaBlendDestination(
	WC_Kore_Graphics4_PipelineState* self) {
	return (WE_Kore_Graphics4_BlendingOperation)reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->alphaBlendDestination;
}

void Kore_Graphics4_PipelineState_setAlphaBlendDestination(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->alphaBlendDestination = (Kore::Graphics4::BlendingOperation)operation;
}

bool Kore_Graphics4_PipelineState_getColorWriteMaskRed(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskRed;
}

void Kore_Graphics4_PipelineState_setColorWriteMaskRed(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskRed = value;
}

bool Kore_Graphics4_PipelineState_getColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskGreen;
}

void Kore_Graphics4_PipelineState_setColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskGreen = value;
}

bool Kore_Graphics4_PipelineState_getColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskBlue;
}

void Kore_Graphics4_PipelineState_setColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskBlue = value;
}

bool Kore_Graphics4_PipelineState_getColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskAlpha;
}

void Kore_Graphics4_PipelineState_setColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->colorWriteMaskAlpha = value;
}

bool Kore_Graphics4_PipelineState_getConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self) {
	return reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->conservativeRasterization;
}

void Kore_Graphics4_PipelineState_setConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self,
	bool value) {
	reinterpret_cast<Kore::Graphics4::PipelineState*>(self)->conservativeRasterization = value;
}

#ifdef __cplusplus
}
#endif
