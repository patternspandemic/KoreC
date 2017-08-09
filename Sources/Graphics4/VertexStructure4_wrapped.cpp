#include <Kore/pch.h>
#include <Kore/Graphics4/VertexStructure.h>

#include <assert.h>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Guard against enum changes.
*/

// Kore::Graphics4::VertexData assertions
static_assert(
  WE_VertexDataNoVertexData == Kore::Graphics4::VertexData::NoVertexData,
  "Kore::Graphics4::VertexData::NoVertexData enum value changed.");
static_assert(
  WE_VertexDataFloat1VertexData == Kore::Graphics4::VertexData::Float1VertexData,
  "Kore::Graphics4::VertexData::Float1VertexData enum value changed.");
static_assert(
  WE_VertexDataFloat2VertexData == Kore::Graphics4::VertexData::Float2VertexData,
  "Kore::Graphics4::VertexData::Float2VertexData enum value changed.");
static_assert(
  WE_VertexDataFloat3VertexData == Kore::Graphics4::VertexData::Float3VertexData,
  "Kore::Graphics4::VertexData::Float3VertexData enum value changed.");
static_assert(
  WE_VertexDataFloat4VertexData == Kore::Graphics4::VertexData::Float4VertexData,
  "Kore::Graphics4::VertexData::Float4VertexData enum value changed.");
static_assert(
  WE_VertexDataFloat4x4VertexData == Kore::Graphics4::VertexData::Float4x4VertexData,
  "Kore::Graphics4::VertexData::Float4x4VertexData enum value changed.");
static_assert(
  WE_VertexDataColorVertexData == Kore::Graphics4::VertexData::ColorVertexData,
  "Kore::Graphics4::VertexData::ColorVertexData enum value changed.");

// Kore::Graphics4::VertexAttribute assertions
static_assert(
  WE_VertexAttributeNoVertexAttribute == Kore::Graphics4::VertexAttribute::NoVertexAttribute,
  "Kore::Graphics4::VertexAttribute::NoVertexAttribute enum value changed.");
static_assert(
  WE_VertexAttributeVertexCoord == Kore::Graphics4::VertexAttribute::VertexCoord,
  "Kore::Graphics4::VertexAttribute::VertexCoord enum value changed.");
static_assert(
  WE_VertexAttributeVertexNormal == Kore::Graphics4::VertexAttribute::VertexNormal,
  "Kore::Graphics4::VertexAttribute::VertexNormal enum value changed.");
static_assert(
  WE_VertexAttributeVertexColor0 == Kore::Graphics4::VertexAttribute::VertexColor0,
  "Kore::Graphics4::VertexAttribute::VertexColor0 enum value changed.");
static_assert(
  WE_VertexAttributeVertexColor1 == Kore::Graphics4::VertexAttribute::VertexColor1,
  "Kore::Graphics4::VertexAttribute::VertexColor1 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord0 == Kore::Graphics4::VertexAttribute::VertexTexCoord0,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord0 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord1 == Kore::Graphics4::VertexAttribute::VertexTexCoord1,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord1 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord2 == Kore::Graphics4::VertexAttribute::VertexTexCoord2,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord2 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord3 == Kore::Graphics4::VertexAttribute::VertexTexCoord3,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord3 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord4 == Kore::Graphics4::VertexAttribute::VertexTexCoord4,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord4 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord5 == Kore::Graphics4::VertexAttribute::VertexTexCoord5,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord5 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord6 == Kore::Graphics4::VertexAttribute::VertexTexCoord6,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord6 enum value changed.");
static_assert(
  WE_VertexAttributeVertexTexCoord7 == Kore::Graphics4::VertexAttribute::VertexTexCoord7,
  "Kore::Graphics4::VertexAttribute::VertexTexCoord7 enum value changed.");

/* Kore::Graphics4::VertexElement */

// .. constructors
WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_create() {
  return reinterpret_cast<WC_Kore_Graphics4_VertexElement*>(
		new Kore::Graphics4::VertexElement());
}

WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_createND(
	const char* name, WE_Kore_Graphics4_VertexData data) {
  return reinterpret_cast<WC_Kore_Graphics4_VertexElement*>(
		new Kore::Graphics4::VertexElement(
      name, (Kore::Graphics4::VertexData)data));
}

WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_createAD(
	WE_Kore_Graphics4_VertexAttribute attribute,
	WE_Kore_Graphics4_VertexData data) {
  return reinterpret_cast<WC_Kore_Graphics4_VertexElement*>(
		new Kore::Graphics4::VertexElement(
      (Kore::Graphics4::VertexAttribute)attribute,
      (Kore::Graphics4::VertexData)data));
}

// .. destructor
void Kore_Graphics4_VertexElement_destroy(
	WC_Kore_Graphics4_VertexElement* self) {
  delete reinterpret_cast<Kore::Graphics4::VertexElement*>(self);
}

// .. data access
const char* Kore_Graphics4_VertexElement_name(
	WC_Kore_Graphics4_VertexElement* self) {
  return reinterpret_cast<Kore::Graphics4::VertexElement*>(self)->name;
}

WE_Kore_Graphics4_VertexAttribute Kore_Graphics4_VertexElement_attribute(
	WC_Kore_Graphics4_VertexElement* self) {
  return (WE_Kore_Graphics4_VertexAttribute)reinterpret_cast<Kore::Graphics4::VertexElement*>(self)->attribute;
}

WE_Kore_Graphics4_VertexData Kore_Graphics4_VertexElement_data(
	WC_Kore_Graphics4_VertexElement* self) {
  return (WE_Kore_Graphics4_VertexData)reinterpret_cast<Kore::Graphics4::VertexElement*>(self)->data;
}

/* Kore::Graphics4::VertexStructure */

// .. constructors
WC_Kore_Graphics4_VertexStructure* Kore_Graphics4_VertexStructure_create() {
  return reinterpret_cast<WC_Kore_Graphics4_VertexStructure*>(
		new Kore::Graphics4::VertexStructure());
}

// .. destructor
void Kore_Graphics4_VertexStructure_destroy(
	WC_Kore_Graphics4_VertexStructure* self) {
  delete reinterpret_cast<Kore::Graphics4::VertexStructure*>(self);
}

// .. methods
void Kore_Graphics4_VertexStructure_addND(
  WC_Kore_Graphics4_VertexStructure* self,
	const char* name, WE_Kore_Graphics4_VertexData data)
{
  reinterpret_cast<Kore::Graphics4::VertexStructure*>(self)->add(
    name, (Kore::Graphics4::VertexData)data);
}

void Kore_Graphics4_VertexStructure_addAD(
  WC_Kore_Graphics4_VertexStructure* self,
	WE_Kore_Graphics4_VertexAttribute attribute,
	WE_Kore_Graphics4_VertexData data)
{
  reinterpret_cast<Kore::Graphics4::VertexStructure*>(self)->add(
    (Kore::Graphics4::VertexAttribute)attribute,
    (Kore::Graphics4::VertexData)data);
}

// .. data access
// TODO: Verify return type of Kore_Graphics4_VertexStructure_elements
WC_Kore_Graphics4_VertexElement** Kore_Graphics4_VertexStructure_elements(
	WC_Kore_Graphics4_VertexStructure* self) {
  return reinterpret_cast<WC_Kore_Graphics4_VertexElement**>(
    reinterpret_cast<Kore::Graphics4::VertexStructure*>(self)->elements);
}

int Kore_Graphics4_VertexStructure_size(
	WC_Kore_Graphics4_VertexStructure* self) {
  return reinterpret_cast<Kore::Graphics4::VertexStructure*>(self)->size;
}

bool Kore_Graphics4_VertexStructure_instanced(
	WC_Kore_Graphics4_VertexStructure* self) {
  return reinterpret_cast<Kore::Graphics4::VertexStructure*>(self)->instanced;
}

// .. static members
int Kore_Graphics4_VertexStructure_maxElementsCount() {
  return Kore::Graphics4::VertexStructure::maxElementsCount;
}

#ifdef __cplusplus
}
#endif
