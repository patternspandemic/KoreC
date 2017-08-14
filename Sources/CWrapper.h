#include <Kore/pch.h>

/**** Kore namespaced types ****/

typedef unsigned char u8;   // 1 Byte
typedef unsigned short u16; // 2 Byte
typedef unsigned int u32; // 4 Byte
#ifdef KORE_WINDOWS
	typedef unsigned __int64 u64; // 8 Byte
#else
	typedef unsigned long long u64;
#endif
typedef char s8;   // 1 Byte
typedef short s16; // 2 Byte
typedef int s32; // 4 Byte
#ifdef KORE_WINDOWS
	typedef __int64 s64; // 8 Byte
#else
	typedef long long s64;
#endif
typedef u32 uint; // 4 Byte
typedef s32 sint; // 4 Byte
#ifdef KORE_64
	typedef s64 spint;
	typedef u64 upint;
#else
	typedef s32 spint;
	typedef u32 upint;
#endif

#ifdef __cplusplus
extern "C" {
#endif





/**** Window ****/

// Kore::RendererOptions
struct WS_Kore_RendererOptions;
typedef struct WS_Kore_RendererOptions {
	int textureFormat;
	int depthBufferBits;
	int stencilBufferBits;
	int antialiasing;
} WS_Kore_RendererOptions;

void Kore_RendererOptions_default(WS_Kore_RendererOptions* ro);

// Kore::WindowMode
typedef enum WE_Kore_WindowMode {
	WE_WindowModeWindow = 0,
	WE_WindowModeBorderless = 1,
	WE_WindowModeFullscreen = 2,
} WE_Kore_WindowMode;

// Kore::WindowOptions
struct WS_Kore_WindowOptions;
typedef struct WS_Kore_WindowOptions {
	const char* title;
	int width;
	int height;
	int x;
	int y;
	int targetDisplay;
	bool vSync;
	bool resizable;
	bool maximizable;
	bool minimizable;
	WE_Kore_WindowMode mode;
	bool showWindow;
	WS_Kore_RendererOptions rendererOptions;
} WS_Kore_WindowOptions;

void Kore_WindowOptions_default(WS_Kore_WindowOptions* wo);

/****************/





/**** System ****/

typedef unsigned long long ticks;

// Kore::Orientation
typedef enum WE_Kore_Orientation {
	WE_OrientationLandscapeLeft = 0,
	WE_OrientationLandscapeRight = 1,
	WE_OrientationPortrait = 2,
	WE_OrientationPortraitUpsideDown = 3,
	WE_OrientationUnknown = 4,
} WE_Kore_Orientation;

void Kore_System_init(const char* name, int width, int height);

int Kore_System_currentDevice();

int Kore_System_initWindow(WS_Kore_WindowOptions* options);
void Kore_System_destroyWindow(int id);
void* Kore_System_windowHandle(int windowId);
int Kore_System_windowWidth(int id);
int Kore_System_windowHeight(int id);
int Kore_System_windowCount();

int Kore_System_screenDpi();

void Kore_System_changeResolution(int width, int height, bool fullscreen);
bool Kore_System_handleMessages();
// TODO: Kore::System::mousePos not defined for Linux backend?
// vec2i Kore_System_mousePos();
void Kore_System_showKeyboard();
void Kore_System_hideKeyboard();
// TODO: Kore::System::showsKeyboard not defined for Linux backend?
// bool Kore_System_showsKeyboard();
void Kore_System_loadURL(const char* url);
int Kore_System_desktopWidth();
int Kore_System_desktopHeight();
const char* Kore_System_systemId();
void Kore_System_setTitle(const char* title);
const char* Kore_System_savePath();
const char** Kore_System_videoFormats();
void Kore_System_showWindow();
void Kore_System_swapBuffers(int contextId);
void Kore_System_makeCurrent(int contextId);
void Kore_System_clearCurrent();

double Kore_System_frequency();
ticks Kore_System_timestamp();
double Kore_System_time();

void Kore_System_setName(const char* name);
const char* Kore_System_name();

bool Kore_System_hasShowWindowFlag();
void Kore_System_setShowWindowFlag(bool value);

int Kore_System_simpleSetup(int argc, char* argv[],
							int width, int height,
							int antialiasing,
							WE_Kore_WindowMode mode,
							const char* title,
							bool showWindow);

void Kore_System_setup();
void Kore_System_start();
void Kore_System_stop();
void Kore_System__shutdown();
bool Kore_System_isFullscreen();

void Kore_System_setCallback(void (*value)());
void Kore_System_setForegroundCallback(void (*value)());
void Kore_System_setResumeCallback(void (*value)());
void Kore_System_setPauseCallback(void (*value)());
void Kore_System_setBackgroundCallback(void (*value)());
void Kore_System_setShutdownCallback(void (*value)());
void Kore_System_setOrientationCallback(void (*value)(WE_Kore_Orientation));
void Kore_System_setDropFilesCallback(void (*value)(wchar_t*));
void Kore_System_setKeepScreenOn(bool on);

void Kore_System_callback();
void Kore_System_foregroundCallback();
void Kore_System_resumeCallback();
void Kore_System_pauseCallback();
void Kore_System_backgroundCallback();
void Kore_System_shutdownCallback();
void Kore_System_orientationCallback(WE_Kore_Orientation orientation);
void Kore_System_dropFilesCallback(wchar_t* filePath);

/****************/





/**** Random ****/

// Kore::Random::init -0
// void Kore_Random_init(int seed);
void Kore_Random_init();

/****************/





/**** Graphics1 ****/

// Enums:

// Kore::Graphics1::ImageCompression
typedef enum WE_Kore_Graphics1_ImageCompression {
	WE_ImageCompressionNone = 0,
	WE_ImageCompressionDXT5 = 1,
	WE_ImageCompressionASTC = 2,
	WE_ImageCompressionPVRTC = 3,
} WE_Kore_Graphics1_ImageCompression;

// Kore::Graphics1::Image::Format
typedef enum WE_Kore_Graphics1_Image_Format {
	WE_FormatRGBA32 = 0,
	WE_FormatGrey8 = 1,
	WE_FormatRGB24 = 2,
	WE_FormatRGBA128 = 3,
	WE_FormatRGBA64 = 4,
	WE_FormatA32 = 5,
	WE_FormatBGRA32 = 6,
	WE_FormatA16 = 7,
} WE_Kore_Graphics1_Image_Format;

// Opaque Types to represent classes:

/* Kore::Graphics1::Color */
struct WC_Kore_Graphics1_Color;
typedef struct WC_Kore_Graphics1_Color WC_Kore_Graphics1_Color;
/* Kore::Graphics1::Image */
struct WC_Kore_Graphics1_Image;
typedef struct WC_Kore_Graphics1_Image WC_Kore_Graphics1_Image;

// Classes:

/* Kore::Graphics1::Color */
// .. constructors
WC_Kore_Graphics1_Color* Kore_Graphics1_Color_create(uint color);
// .. destructor, TODO: Kore_Graphics1_Color_destroy needed with no dynallocs?
void Kore_Graphics1_Color_destroy(WC_Kore_Graphics1_Color* self);
// .. static members
// TODO: A bunch of colors in hex

/* Kore::Graphics1::Image */
// .. constructors
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHFR(
	int width, int height, WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createWHDFR(
	int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createFR(
	const char* filename, bool readable);
// TODO: Check reader param syntax & need to expose Reader class if useful?
// WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createRFR(
// 	WC_Kore_Reader& reader, const char* format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHFR(
	void* data, int width, int height,
	WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics1_Image* Kore_Graphics1_Image_createDWHDFR(
	void* data, int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
// .. destructor
void Kore_Graphics1_Image_destroy(WC_Kore_Graphics1_Image* self);
// .. methods
int Kore_Graphics1_Image_at(WC_Kore_Graphics1_Image* self, int x, int y);
// .. data accessors
int Kore_Graphics1_Image_width(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_height(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_depth(WC_Kore_Graphics1_Image* self);
WE_Kore_Graphics1_Image_Format Kore_Graphics1_Image_format(
	WC_Kore_Graphics1_Image* self);
bool Kore_Graphics1_Image_readable(WC_Kore_Graphics1_Image* self);
WE_Kore_Graphics1_ImageCompression Kore_Graphics1_Image_compression(
	WC_Kore_Graphics1_Image* self);
u8* Kore_Graphics1_Image_data(WC_Kore_Graphics1_Image* self);
float* Kore_Graphics1_Image_hdrData(WC_Kore_Graphics1_Image* self);
int Kore_Graphics1_Image_dataSize(WC_Kore_Graphics1_Image* self);
unsigned Kore_Graphics1_Image_internalFormat(WC_Kore_Graphics1_Image* self);
// .. static members
int Kore_Graphics1_Image_sizeOf(WE_Kore_Graphics1_Image_Format format);

/*******************/





/**** Graphics2 ****/

// Enums:

// Kore::Graphics2::ImageScaleQuality
typedef enum WE_Kore_Graphics2_ImageScaleQuality {
	WE_ImageScaleQualityLow = 0,
	WE_ImageScaleQualityHigh = 1,
} WE_Kore_Graphics2_ImageScaleQuality;

// Opaque Types to represent classes:

// Classes:
//   Kore::Graphics2::Color? typedef'd from Kore::Graphics1::Color
//   Kore::Graphics2::Graphics2
//   Kore::Graphics2::ImageShaderPainter
//   Kore::Graphics2::ColoredShaderPainter
//   Kore::Graphics2::TextShaderPainter
//   Kore::Kravur stuff? see graphics2 Kravur.h

/*******************/





/**** Graphics4 ****/

// Enums:

//   Graphics.h
// Kore::Graphics4::TextureAddressing
typedef enum WE_Kore_Graphics4_TextureAddressing {
	WE_TextureAddressingRepeat = 0,
	WE_TextureAddressingMirror = 1,
	WE_TextureAddressingClamp = 2,
	WE_TextureAddressingBorder = 3,
} WE_Kore_Graphics4_TextureAddressing;

// Kore::Graphics4::TextureFilter
typedef enum WE_Kore_Graphics4_TextureFilter {
	WE_TextureFilterPointFilter = 0,
	WE_TextureFilterLinearFilter = 1,
	WE_TextureFilterAnisotropicFilter = 2,
} WE_Kore_Graphics4_TextureFilter;

// Kore::Graphics4::MipmapFilter
typedef enum WE_Kore_Graphics4_MipmapFilter {
	WE_MipmapFilterNoMipFilter = 0,
	WE_MipmapFilterPointMipFilter = 1,
	WE_MipmapFilterLinearMipFilter = 2,
} WE_Kore_Graphics4_MipmapFilter;

// Kore::Graphics4::RenderState
typedef enum WE_Kore_Graphics4_RenderState {
	WE_RenderStateBlendingState = 0,
	WE_RenderStateDepthTest = 1,
	WE_RenderStateDepthTestCompare = 2,
	WE_RenderStateDepthWrite = 3,
	WE_RenderStateNormalize = 4,
	WE_RenderStateBackfaceCulling = 5,
	WE_RenderStateScissorTestState = 6,
	WE_RenderStateAlphaTestState = 7,
	WE_RenderStateAlphaReferenceState = 8,
	WE_RenderStateConservativeRasterization = 9,
} WE_Kore_Graphics4_RenderState;

// Kore::Graphics4::BlendingOperation
typedef enum WE_Kore_Graphics4_BlendingOperation {
	WE_BlendingOperationBlendOne = 0,
	WE_BlendingOperationBlendZero = 1,
	WE_BlendingOperationSourceAlpha = 2,
	WE_BlendingOperationDestinationAlpha = 3,
	WE_BlendingOperationInverseSourceAlpha = 4,
	WE_BlendingOperationInverseDestinationAlpha = 5,
	WE_BlendingOperationSourceColor = 6,
	WE_BlendingOperationDestinationColor = 7,
	WE_BlendingOperationInverseSourceColor = 8,
	WE_BlendingOperationInverseDestinationColor = 9,
} WE_Kore_Graphics4_BlendingOperation;

// Kore::Graphics4::ZCompareMode
typedef enum WE_Kore_Graphics4_ZCompareMode {
	WE_ZCompareModeZCompareAlways = 0,
	WE_ZCompareModeZCompareNever = 1,
	WE_ZCompareModeZCompareEqual = 2,
	WE_ZCompareModeZCompareNotEqual = 3,
	WE_ZCompareModeZCompareLess = 4,
	WE_ZCompareModeZCompareLessEqual = 5,
	WE_ZCompareModeZCompareGreater = 6,
	WE_ZCompareModeZCompareGreaterEqual = 7,
} WE_Kore_Graphics4_ZCompareMode;

// Kore::Graphics4::CullMode
typedef enum WE_Kore_Graphics4_CullMode {
	WE_CullModeClockwise = 0,
	WE_CullModeCounterClockwise = 1,
	WE_CullModeNoCulling = 2,
} WE_Kore_Graphics4_CullMode;

// Kore::Graphics4::TexDir
typedef enum WE_Kore_Graphics4_TexDir {
	WE_TexDirU = 0,
	WE_TexDirV = 1,
	WE_TexDirW = 2,
} WE_Kore_Graphics4_TexDir;

// Kore::Graphics4::FogType
typedef enum WE_Kore_Graphics4_FogType {
	WE_FogTypeLinearFog = 0,
} WE_Kore_Graphics4_FogType;

// Kore::Graphics4::RenderTargetFormat
typedef enum WE_Kore_Graphics4_RenderTargetFormat {
	WE_RenderTargetFormatTarget32Bit = 0,
	WE_RenderTargetFormatTarget64BitFloat = 1,
	WE_RenderTargetFormatTarget32BitRedFloat = 2,
	WE_RenderTargetFormatTarget128BitFloat = 3,
	WE_RenderTargetFormatTarget16BitDepth = 4,
	WE_RenderTargetFormatTarget8BitRed = 5,
	WE_RenderTargetFormatTarget16BitRedFloat = 6,
} WE_Kore_Graphics4_RenderTargetFormat;

// Kore::Graphics4::StencilAction
typedef enum WE_Kore_Graphics4_StencilAction {
	WE_StencilActionKeep = 0,
	WE_StencilActionZero = 1,
	WE_StencilActionReplace = 2,
	WE_StencilActionIncrement = 3,
	WE_StencilActionIncrementWrap = 4,
	WE_StencilActionDecrement = 5,
	WE_StencilActionDecrementWrap = 6,
	WE_StencilActionInvert = 7,
} WE_Kore_Graphics4_StencilAction;

// Kore::Graphics4::TextureOperation
typedef enum WE_Kore_Graphics4_TextureOperation {
	WE_TextureOperationModulateOperation = 0,
	WE_TextureOperationSelectFirstOperation = 1,
	WE_TextureOperationSelectSecondOperation = 2,
} WE_Kore_Graphics4_TextureOperation;

// Kore::Graphics4::TextureArgument
typedef enum WE_Kore_Graphics4_TextureArgument {
	WE_TextureArgumentCurrentColorArgument = 0,
	WE_TextureArgumentTextureColorArgument = 1,
} WE_Kore_Graphics4_TextureArgument;

//   Shader.h
// Kore::Graphics4::ShaderType
typedef enum WE_Kore_Graphics4_ShaderType {
	WE_ShaderTypeFragmentShader = 0,
	WE_ShaderTypeVertexShader = 1,
	WE_ShaderTypeGeometryShader = 2,
	WE_ShaderTypeTessellationControlShader = 3,
	WE_ShaderTypeTessellationEvaluationShader = 4,
} WE_Kore_Graphics4_ShaderType;

//   VertexStructure.h
// Kore::Graphics4::VertexData
typedef enum WE_Kore_Graphics4_VertexData {
	WE_VertexDataNoVertexData = 0,
	WE_VertexDataFloat1VertexData = 1,
	WE_VertexDataFloat2VertexData = 2,
	WE_VertexDataFloat3VertexData = 3,
	WE_VertexDataFloat4VertexData = 4,
	WE_VertexDataFloat4x4VertexData = 5,
	WE_VertexDataColorVertexData = 6,
} WE_Kore_Graphics4_VertexData;

// Kore::Graphics4::VertexAttribute
typedef enum WE_Kore_Graphics4_VertexAttribute {
	WE_VertexAttributeNoVertexAttribute = 0,
	WE_VertexAttributeVertexCoord = 1,
	WE_VertexAttributeVertexNormal = 2,
	WE_VertexAttributeVertexColor0 = 3,
	WE_VertexAttributeVertexColor1 = 4,
	WE_VertexAttributeVertexTexCoord0 = 5,
	WE_VertexAttributeVertexTexCoord1 = 6,
	WE_VertexAttributeVertexTexCoord2 = 7,
	WE_VertexAttributeVertexTexCoord3 = 8,
	WE_VertexAttributeVertexTexCoord4 = 9,
	WE_VertexAttributeVertexTexCoord5 = 10,
	WE_VertexAttributeVertexTexCoord6 = 11,
	WE_VertexAttributeVertexTexCoord7 = 12,
} WE_Kore_Graphics4_VertexAttribute;

// Opaque Types to represent classes:

/* Kore::Graphics4::VertexBuffer */
struct WC_Kore_Graphics4_VertexBuffer;
typedef struct WC_Kore_Graphics4_VertexBuffer WC_Kore_Graphics4_VertexBuffer;
/* Kore::Graphics4::IndexBuffer */
struct WC_Kore_Graphics4_IndexBuffer;
typedef struct WC_Kore_Graphics4_IndexBuffer WC_Kore_Graphics4_IndexBuffer;
/* Kore::Graphics4::RenderTarget */
struct WC_Kore_Graphics4_RenderTarget;
typedef struct WC_Kore_Graphics4_RenderTarget WC_Kore_Graphics4_RenderTarget;
/* Kore::Graphics4::PipelineState */
struct WC_Kore_Graphics4_PipelineState;
typedef struct WC_Kore_Graphics4_PipelineState WC_Kore_Graphics4_PipelineState;
/* Kore::Graphics4::Shader */
struct WC_Kore_Graphics4_Shader;
typedef struct WC_Kore_Graphics4_Shader WC_Kore_Graphics4_Shader;
/* Kore::Graphics4::ConstantLocation */
struct WC_Kore_Graphics4_ConstantLocation;
typedef struct WC_Kore_Graphics4_ConstantLocation WC_Kore_Graphics4_ConstantLocation;
/* Kore::Graphics4::TextureUnit */
struct WC_Kore_Graphics4_TextureUnit;
typedef struct WC_Kore_Graphics4_TextureUnit WC_Kore_Graphics4_TextureUnit;
/* Kore::Graphics4::Texture */
struct WC_Kore_Graphics4_Texture;
typedef struct WC_Kore_Graphics4_Texture WC_Kore_Graphics4_Texture;
/* Kore::Graphics4::TextureArray */
struct WC_Kore_Graphics4_TextureArray;
typedef struct WC_Kore_Graphics4_TextureArray WC_Kore_Graphics4_TextureArray;
/* Kore::Graphics4::VertexElement */
struct WC_Kore_Graphics4_VertexElement;
typedef struct WC_Kore_Graphics4_VertexElement WC_Kore_Graphics4_VertexElement;
/* Kore::Graphics4::VertexStructure */
struct WC_Kore_Graphics4_VertexStructure;
typedef struct WC_Kore_Graphics4_VertexStructure WC_Kore_Graphics4_VertexStructure;

// Classes:

//   Graphics.h
/* Kore::Graphics4::VertexBuffer */
// .. constructors
// TODO: How to pass const VertexStructure& structure?
WC_Kore_Graphics4_VertexBuffer* Kore_Graphics4_VertexBuffer_create(
	int count, WC_Kore_Graphics4_VertexStructure* structure, int instanceDataStepRate);
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

//   PipelineState.h
/* Kore::Graphics4::PipelineState */
// .. constructors
WC_Kore_Graphics4_PipelineState* Kore_Graphics4_PipelineState_create();
// .. destructor
void Kore_Graphics4_PipelineState_destroy(
	WC_Kore_Graphics4_PipelineState* self);
// .. methods
void Kore_Graphics4_PipelineState_compile(
	WC_Kore_Graphics4_PipelineState* self);
WC_Kore_Graphics4_ConstantLocation* Kore_Graphics4_PipelineState_getConstantLocation(
	WC_Kore_Graphics4_PipelineState* self, const char* name);
WC_Kore_Graphics4_TextureUnit* Kore_Graphics4_PipelineState_getTextureUnit(
	WC_Kore_Graphics4_PipelineState* self, const char* name);
// .. data accessors
// TODO: Verify WC_Kore_Graphics4_VertexStructure** return
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
	WC_Kore_Graphics4_PipelineState* self, bool value);
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
	WC_Kore_Graphics4_PipelineState* self, int value);
int Kore_Graphics4_PipelineState_getStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilReadMask(
	WC_Kore_Graphics4_PipelineState* self, int value);
int Kore_Graphics4_PipelineState_getStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setStencilWriteMask(
	WC_Kore_Graphics4_PipelineState* self, int value);
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
	WC_Kore_Graphics4_PipelineState* self, bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskGreen(
	WC_Kore_Graphics4_PipelineState* self, bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskBlue(
	WC_Kore_Graphics4_PipelineState* self, bool value);
bool Kore_Graphics4_PipelineState_getColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setColorWriteMaskAlpha(
	WC_Kore_Graphics4_PipelineState* self, bool value);
bool Kore_Graphics4_PipelineState_getConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self);
void Kore_Graphics4_PipelineState_setConservativeRasterization(
	WC_Kore_Graphics4_PipelineState* self, bool value);

//   Shader.h
/* Kore::Graphics4::Shader */
// .. constructors
WC_Kore_Graphics4_Shader* Kore_Graphics4_Shader_createDLT(
	void* data, int length, WE_Kore_Graphics4_ShaderType type);
WC_Kore_Graphics4_Shader* Kore_Graphics4_Shader_createST(
	const char* source, WE_Kore_Graphics4_ShaderType type);
// .. destructor
void Kore_Graphics4_Shader_destroy(
	WC_Kore_Graphics4_Shader* self);

/* Kore::Graphics4::ConstantLocation */
// .. constructors
WC_Kore_Graphics4_ConstantLocation* Kore_Graphics4_ConstantLocation_create();
// .. destructor
void Kore_Graphics4_ConstantLocation_destroy(
	WC_Kore_Graphics4_ConstantLocation* self);

//   Texture.h
/* Kore::Graphics4::TextureUnit */
// .. constructors
WC_Kore_Graphics4_TextureUnit* Kore_Graphics4_TextureUnit_create();
// .. destructor
void Kore_Graphics4_TextureUnit_destroy(
	WC_Kore_Graphics4_TextureUnit* self);

/* Kore::Graphics4::Texture */
// .. constructors
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createWHFR(
	int width, int height, WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createWHDFR(
	int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
// TODO: Check reader param syntax & need to expose Reader class if useful?
// WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createRFR(
// 	WC_Kore_Reader& reader, const char* format, bool readable);
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createFR(
	const char* filename, bool readable);
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDSFR(
	void* data, int size, const char* format, bool readable);
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDWHFR(
	void* data, int width, int height,
	WE_Kore_Graphics1_Image_Format format, bool readable);
WC_Kore_Graphics4_Texture* Kore_Graphics4_Texture_createDWHDFR(
	void* data, int width, int height, int depth,
	WE_Kore_Graphics1_Image_Format format, bool readable);
// .. destructor
void Kore_Graphics4_Texture_destroy(
	WC_Kore_Graphics4_Texture* self);
// .. methods
// TODO: Deref WC_Kore_Graphics4_TextureUnit* to pass by val parameter?
// TODO: Remove?
void Kore_Graphics4_Texture__set(
	WC_Kore_Graphics4_Texture* self, WC_Kore_Graphics4_TextureUnit* unit);
// TODO: Deref WC_Kore_Graphics4_TextureUnit* to pass by val parameter?
// TODO: Remove?
void Kore_Graphics4_Texture__setImage(
	WC_Kore_Graphics4_Texture* self, WC_Kore_Graphics4_TextureUnit* unit);
u8* Kore_Graphics4_Texture_lock(WC_Kore_Graphics4_Texture* self);
void Kore_Graphics4_Texture_unlock(WC_Kore_Graphics4_Texture* self);
void Kore_Graphics4_Texture_clear(
	WC_Kore_Graphics4_Texture* self,
	int x, int y, int z, int width, int height,
	int depth, uint color);
#if defined(KORE_IOS) || defined(KORE_MACOS)
void Kore_Graphics4_Texture_upload(
	WC_Kore_Graphics4_Texture* self,
	u8* data, int stride);
#endif
void Kore_Graphics4_Texture_generateMipmaps(
	WC_Kore_Graphics4_Texture* self, int levels);
void Kore_Graphics4_Texture_setMipmap(
	WC_Kore_Graphics4_Texture* self,
	WC_Kore_Graphics4_Texture* mipmap, int level);
int Kore_Graphics4_Texture_stride(WC_Kore_Graphics4_Texture* self);
// .. inherited methods
int Kore_Graphics4_Texture_at(WC_Kore_Graphics4_Texture* self, int x, int y);
// .. data accessors, TODO: Setter needed?
int Kore_Graphics4_Texture_getTexWidth(WC_Kore_Graphics4_Texture* self);
int Kore_Graphics4_Texture_getTexHeight(WC_Kore_Graphics4_Texture* self);
int Kore_Graphics4_Texture_getTexDepth(WC_Kore_Graphics4_Texture* self);
// .. inherited data accessors, TODO: Setters needed?
int Kore_Graphics4_Texture_getWidth(WC_Kore_Graphics4_Texture* self);
int Kore_Graphics4_Texture_getHeight(WC_Kore_Graphics4_Texture* self);
int Kore_Graphics4_Texture_getDepth(WC_Kore_Graphics4_Texture* self);
WE_Kore_Graphics1_Image_Format Kore_Graphics4_Texture_format(
	WC_Kore_Graphics4_Texture* self);
bool Kore_Graphics4_Texture_readable(WC_Kore_Graphics4_Texture* self);
WE_Kore_Graphics1_ImageCompression Kore_Graphics4_Texture_compression(
	WC_Kore_Graphics4_Texture* self);
u8* Kore_Graphics4_Texture_data(WC_Kore_Graphics4_Texture* self);
float* Kore_Graphics4_Texture_hdrData(WC_Kore_Graphics4_Texture* self);
int Kore_Graphics4_Texture_dataSize(WC_Kore_Graphics4_Texture* self);
unsigned Kore_Graphics4_Texture_internalFormat(WC_Kore_Graphics4_Texture* self);

//   TextureArray.h
/* Kore::Graphics4::TextureArray */
// .. constructors
// TODO: Verify proper handling of WC_Kore_Graphics1_Image**
WC_Kore_Graphics4_TextureArray* Kore_Graphics4_TextureArray_create(
	WC_Kore_Graphics1_Image** textures, int count);
// .. destructor
void Kore_Graphics4_TextureArray_destroy(
	WC_Kore_Graphics4_TextureArray* self);

//   VertexStructure.h
/* Kore::Graphics4::VertexElement */
// .. constructors
WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_create();
WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_createND(
	const char* name, WE_Kore_Graphics4_VertexData data);
WC_Kore_Graphics4_VertexElement* Kore_Graphics4_VertexElement_createAD(
	WE_Kore_Graphics4_VertexAttribute attribute,
	WE_Kore_Graphics4_VertexData data);
// .. destructor
void Kore_Graphics4_VertexElement_destroy(
	WC_Kore_Graphics4_VertexElement* self);
// .. data accessors, TODO: Setter needed?
const char* Kore_Graphics4_VertexElement_getName(
	WC_Kore_Graphics4_VertexElement* self);
WE_Kore_Graphics4_VertexAttribute Kore_Graphics4_VertexElement_getAttribute(
	WC_Kore_Graphics4_VertexElement* self);
WE_Kore_Graphics4_VertexData Kore_Graphics4_VertexElement_getData(
	WC_Kore_Graphics4_VertexElement* self);

/* Kore::Graphics4::VertexStructure */
// .. constructors
WC_Kore_Graphics4_VertexStructure* Kore_Graphics4_VertexStructure_create();
// .. destructor
void Kore_Graphics4_VertexStructure_destroy(
	WC_Kore_Graphics4_VertexStructure* self);
// .. methods
void Kore_Graphics4_VertexStructure_addND(
	WC_Kore_Graphics4_VertexStructure* self,
	const char* name, WE_Kore_Graphics4_VertexData data);
void Kore_Graphics4_VertexStructure_addAD(
	WC_Kore_Graphics4_VertexStructure* self,
	WE_Kore_Graphics4_VertexAttribute attribute,
	WE_Kore_Graphics4_VertexData data);
// .. data accessors, TODO: Setter needed? I think not.
// TODO: Verify return type of Kore_Graphics4_VertexStructure_getElements
WC_Kore_Graphics4_VertexElement** Kore_Graphics4_VertexStructure_getElements(
	WC_Kore_Graphics4_VertexStructure* self);
int Kore_Graphics4_VertexStructure_getSize(
	WC_Kore_Graphics4_VertexStructure* self);
bool Kore_Graphics4_VertexStructure_getInstanced(
	WC_Kore_Graphics4_VertexStructure* self);
// .. static members
int Kore_Graphics4_VertexStructure_maxElementsCount();

// Functions:

void Kore_Graphics4_setBool(
	WC_Kore_Graphics4_ConstantLocation* location, bool value);
void Kore_Graphics4_setInt(
	WC_Kore_Graphics4_ConstantLocation* location, int value);
void Kore_Graphics4_setFloat(
	WC_Kore_Graphics4_ConstantLocation* location, float value);
void Kore_Graphics4_setFloat2(
	WC_Kore_Graphics4_ConstantLocation* location, float value1, float value2);
// TODO: vec2 to wrapped equiv
// void Kore_Graphics4_setFloat2Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec2 value);
void Kore_Graphics4_setFloat3(
	WC_Kore_Graphics4_ConstantLocation* location,
	float value1, float value2, float value3);
	// TODO: vec3 to wrapped equiv
// void Kore_Graphics4_setFloat3Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec3 value);
void Kore_Graphics4_setFloat4(
	WC_Kore_Graphics4_ConstantLocation* location,
	float value1, float value2, float value3, float value4);
// TODO: vec4 to wrapped equiv
// void Kore_Graphics4_setFloat4Vec(
// 	WC_Kore_Graphics4_ConstantLocation* location, vec4 value);
void Kore_Graphics4_setFloats(
	WC_Kore_Graphics4_ConstantLocation* location, float* floats, int count);
// TODO: mat3 to wrapped equiv
// void Kore_Graphics4_setMatrix3(
// 	WC_Kore_Graphics4_ConstantLocation* location, mat3* value);
// TODO: mat4 to wrapped equiv
// void Kore_Graphics4_setMatrix4(
// 	WC_Kore_Graphics4_ConstantLocation* location, mat4* value);

void Kore_Graphics4_setVertexBuffer(
	WC_Kore_Graphics4_VertexBuffer* vertexBuffer);
void Kore_Graphics4_setVertexBuffers(
	WC_Kore_Graphics4_VertexBuffer** vertexBuffers, int count);
void Kore_Graphics4_setIndexBuffer(
	WC_Kore_Graphics4_IndexBuffer* indexBuffer);
void Kore_Graphics4_setTexture(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_Texture* texture);
void Kore_Graphics4_setTextureArray(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_TextureArray* array);
void Kore_Graphics4_setImageTexture(
	WC_Kore_Graphics4_TextureUnit* unit, WC_Kore_Graphics4_Texture* texture);
void Kore_Graphics4_setPipeline(WC_Kore_Graphics4_PipelineState* pipeline);

void Kore_Graphics4_drawIndexedVertices();
void Kore_Graphics4_drawIndexedVerticesSC(
	int start, int count);
void Kore_Graphics4_drawIndexedVerticesInstancedI(
	int instanceCount);
void Kore_Graphics4_drawIndexedVerticesInstancedISC(
	int instanceCount, int start, int count);

void Kore_Graphics4_changeResolution(int width, int height);
bool Kore_Graphics4_hasWindow();
void Kore_Graphics4_setWindow(bool value);
int Kore_Graphics4_antialiasingSamples();
void Kore_Graphics4_setAntialiasingSamples(int samples);

bool Kore_Graphics4_renderTargetsInvertedY();
void Kore_Graphics4_setRenderTargets(
	WC_Kore_Graphics4_RenderTarget** targets, int count);
void Kore_Graphics4_setRenderTarget(WC_Kore_Graphics4_RenderTarget* target);
void Kore_Graphics4_setRenderTargetFace(
	WC_Kore_Graphics4_RenderTarget* texture, int face);
void Kore_Graphics4_restoreRenderTarget();

void Kore_Graphics4_setup();
bool Kore_Graphics4_swapBuffers(int windowId);
void Kore_Graphics4_begin(int windowId);
void Kore_Graphics4_end(int windowId);
void Kore_Graphics4_makeCurrent(int windowId);
void Kore_Graphics4_clearCurrent();

void Kore_Graphics4_viewport(int x, int y, int width, int height);
void Kore_Graphics4_scissor(int x, int y, int width, int height);
void Kore_Graphics4_disableScissor();

void Kore_Graphics4_setTextureAddressing(
	WC_Kore_Graphics4_TextureUnit* unit,
	WE_Kore_Graphics4_TexDir dir,
	WE_Kore_Graphics4_TextureAddressing addressing);
void Kore_Graphics4_setTextureMagnificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter);
void Kore_Graphics4_setTextureMinificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter);
void Kore_Graphics4_setTextureMipmapFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_MipmapFilter filter);
void Kore_Graphics4_setTexture3DAddressing(
	WC_Kore_Graphics4_TextureUnit* unit,
	WE_Kore_Graphics4_TexDir dir,
	WE_Kore_Graphics4_TextureAddressing addressing);
void Kore_Graphics4_setTexture3DMagnificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter);
void Kore_Graphics4_setTexture3DMinificationFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_TextureFilter filter);
void Kore_Graphics4_setTexture3DMipmapFilter(
	WC_Kore_Graphics4_TextureUnit* texunit,
	WE_Kore_Graphics4_MipmapFilter filter);
void Kore_Graphics4_setTextureOperation(
	WE_Kore_Graphics4_TextureOperation operation,
	WE_Kore_Graphics4_TextureArgument arg1,
	WE_Kore_Graphics4_TextureArgument arg2);

bool Kore_Graphics4_vsynced();
unsigned Kore_Graphics4_refreshRate();
bool Kore_Graphics4_nonPow2TexturesSupported();

bool Kore_Graphics4_initOcclusionQuery(uint* occlusionQuery);
void Kore_Graphics4_deleteOcclusionQuery(uint occlusionQuery);
void Kore_Graphics4_renderOcclusionQuery(uint occlusionQuery, int triangles);
bool Kore_Graphics4_isQueryResultsAvailable(uint occlusionQuery);
void Kore_Graphics4_getQueryResults(uint occlusionQuery, uint* pixelCount);

const uint Kore_Graphics4_ClearColorFlag = 1;
const uint Kore_Graphics4_ClearDepthFlag = 2;
const uint Kore_Graphics4_ClearStencilFlag = 4;

void Kore_Graphics4_clear(uint flags, uint color, float depth, int stencil);

void Kore_Graphics4_init(
	int windowId, int depthBufferBits, int stencilBufferBits, bool vsync);
void Kore_Graphics4_destroy(int windowId);

bool Kore_Graphics4_getFullscreen();

void Kore_Graphics4_flush();

/*******************/





#ifdef __cplusplus
}
#endif
