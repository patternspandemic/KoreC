#include <Kore/pch.h>
#include <Kore/Graphics4/Shader.h>

#include <assert.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::Graphics4::ShaderType assertions
static_assert(
  WE_ShaderTypeFragmentShader == Kore::Graphics4::ShaderType::FragmentShader,
  "Kore::Graphics4::ShaderType::FragmentShader enum value changed.");
static_assert(
  WE_ShaderTypeVertexShader == Kore::Graphics4::ShaderType::VertexShader,
  "Kore::Graphics4::ShaderType::VertexShader enum value changed.");
static_assert(
  WE_ShaderTypeGeometryShader == Kore::Graphics4::ShaderType::GeometryShader,
  "Kore::Graphics4::ShaderType::GeometryShader enum value changed.");
static_assert(
  WE_ShaderTypeTessellationControlShader == Kore::Graphics4::ShaderType::TessellationControlShader,
  "Kore::Graphics4::ShaderType::TessellationControlShader enum value changed.");
static_assert(
  WE_ShaderTypeTessellationEvaluationShader == Kore::Graphics4::ShaderType::TessellationEvaluationShader,
  "Kore::Graphics4::ShaderType::TessellationEvaluationShader enum value changed.");

/* Kore::Graphics4::Shader */

// .. constructors
WC_Kore_Graphics4_Shader* Kore_Graphics4_Shader_createDLT(
	void* data, int length, WE_Kore_Graphics4_ShaderType type) {
  return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		new Kore::Graphics4::Shader(
      data, length, (Kore::Graphics4::ShaderType)type));
}

// Beware, this is not portable
WC_Kore_Graphics4_Shader* Kore_Graphics4_Shader_createST(
	const char* source, WE_Kore_Graphics4_ShaderType type) {
  return reinterpret_cast<WC_Kore_Graphics4_Shader*>(
		new Kore::Graphics4::Shader(
      source, (Kore::Graphics4::ShaderType)type));
}

// .. destructor
void Kore_Graphics4_Shader_destroy(
	WC_Kore_Graphics4_Shader* self) {
  delete reinterpret_cast<Kore::Graphics4::Shader*>(self);
}

/* Kore::Graphics4::ConstantLocation */

// .. constructors
WC_Kore_Graphics4_ConstantLocation* Kore_Graphics4_ConstantLocation_create() {
  return reinterpret_cast<WC_Kore_Graphics4_ConstantLocation*>(
		new Kore::Graphics4::ConstantLocation());
}

// .. destructor
void Kore_Graphics4_ConstantLocation_destroy(
	WC_Kore_Graphics4_ConstantLocation* self) {
  delete reinterpret_cast<Kore::Graphics4::ConstantLocation*>(self);
}

#ifdef __cplusplus
}
#endif
