#include <Kore/pch.h>
#include <Kore/Graphics4/PipelineState.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Kore::Graphics4::PipelineState */

// .. constructors
WC_Kore_Graphics4_PipelineState* Kore_Graphics4_PipelineState_create();

// .. destructor
void Kore_Graphics4_PipelineState_destroy(
	WC_Kore_Graphics4_PipelineState* self);

// .. methods
void Kore_Graphics4_PipelineState_compile(
	WC_Kore_Graphics4_PipelineState* self);
// TODO: Turn returned ConstantLocation to WC_Kore_Graphics4_ConstantLocation* ?
WC_Kore_Graphics4_ConstantLocation* Kore_Graphics4_PipelineState_getConstantLocation(
	WC_Kore_Graphics4_PipelineState* self, const char* name);
// TODO: Turn returned TextureUnit to WC_Kore_Graphics4_TextureUnit* ?
WC_Kore_Graphics4_TextureUnit* Kore_Graphics4_PipelineState_getTextureUnit(
	WC_Kore_Graphics4_PipelineState* self, const char* name);

// .. data accessors
WC_Kore_Graphics4_VertexStructure** Kore_Graphics4_PipelineState_getInputLayout(
	WC_Kore_Graphics4_PipelineState* self);
WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getVertexShader(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setVertexShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader);
WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getFragmentShader(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setFragmentShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader);
WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getGeometryShader(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setGeometryShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader);
WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getTessellationControlShader(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setTessellationControlShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader);
WC_Kore_Graphics4_Shader* Kore_Graphics4_PipelineState_getTessellationEvaluationShader(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setTessellationEvaluationShader(
	WC_Kore_Graphics4_PipelineState* self,
	WC_Kore_Graphics4_Shader* shader);
WE_Kore_Graphics4_CullMode Kore_Graphics4_PipelineState_getCullMode(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setCullMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_CullMode mode);
bool Kore_Graphics4_PipelineState_getDepthWrite(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setDepthWrite(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);
WE_Kore_Graphics4_ZCompareMode Kore_Graphics4_PipelineState_getDepthMode(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setDepthMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_ZCompareMode mode);
WE_Kore_Graphics4_ZCompareMode Kore_Graphics4_PipelineState_getStencilMode(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilMode(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_ZCompareMode mode);
WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilBothPass(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilBothPass(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action);
WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilDepthFail(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilDepthFail(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action);
WE_Kore_Graphics4_StencilAction Kore_Graphics4_PipelineState_getStencilFail(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilFail(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_StencilAction action);
int Kore_Graphics4_PipelineState_getStencilReferenceValue(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilReferenceValue(
	WC_Kore_Graphics4_PipelineState* self,
	int value);
int Kore_Graphics4_PipelineState_getStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self,
	int value);
int Kore_Graphics4_PipelineState_getStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self,
	int value);
// TODO: One, Zero deactivates blending, add convenience funcs
WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getBlendSource(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setBlendSource(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation);
WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getBlendDestination(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setBlendDestination(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation);
WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getAlphaBlendSource(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setAlphaBlendSource(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation);
WE_Kore_Graphics4_BlendingOperation Kore_Graphics4_PipelineState_getAlphaBlendDestination(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setAlphaBlendDestination(
	WC_Kore_Graphics4_PipelineState* self,
	WE_Kore_Graphics4_BlendingOperation operation);
bool Kore_Graphics4_PipelineState_getColorWriteMaskRed(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskRed(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);
bool Kore_Graphics4_PipelineState_getConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self,
	bool value);

#ifdef __cplusplus
}
#endif
