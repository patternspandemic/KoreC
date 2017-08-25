#include <Kore/pch.h>
#include <Kore/Math/Vector.h>
#include <Kore/Window.h>
#include <Kore/System.h>
#include <Kore/Graphics4/Graphics.h>

#include <assert.h>

#include "CWrapper.h"

/*
  Guard against enum changes.
*/

// Kore::Orientation assertions
static_assert(WE_OrientationLandscapeLeft == Kore::OrientationLandscapeLeft,
	"Kore::OrientationLandscapeLeft enum value changed.");
static_assert(WE_OrientationLandscapeRight == Kore::OrientationLandscapeRight,
	"Kore::OrientationLandscapeRight enum value changed.");
static_assert(WE_OrientationPortrait == Kore::OrientationPortrait,
	"Kore::OrientationPortrait enum value changed.");
static_assert(WE_OrientationUnknown == Kore::OrientationUnknown,
	"Kore::OrientationUnknown enum value changed.");

// We need to wrap the callback presented to 
// Kore::System::setOrientationCallback to facilitate translation between
// WE_Kore_Orientation enum and its original namespaced Kore::Orientation.
typedef void (*WRAPPED_SETORIENTATIONCALLBACK)(WE_Kore_Orientation);
static WRAPPED_SETORIENTATIONCALLBACK wrapped_setOrientationCallback;
// The wrapping function that does the translation.
static void setOrientationCallback_translator(Kore::Orientation orientation) {
	wrapped_setOrientationCallback((WE_Kore_Orientation)orientation);
}

// TODO: Explain Kore System Object
// typedef void (*KORESYSTEMOBJECTCALLBACK)(KoreSystemObject*);
typedef void (*KORESYSTEMOBJECTCALLBACK)(KoreSystemObject);
static KORESYSTEMOBJECTCALLBACK _koreSystemObjectCallback;
// static KoreSystemObject* koreSystemObject;
static KoreSystemObject _koreSystemObject;

static void koreSystemObjectUpdateCallback() {
	// TODO: Support pause/resume,  backgroung/forground, multiple windows.
	// - see: https://github.com/Kode/Kha/blob/master/Backends/Kore/main.cpp#L125
	// if paused return
	// for each window, if its visible
	Kore::Graphics4::begin();
	_koreSystemObjectCallback(_koreSystemObject);
	Kore::Graphics4::end();
	Kore::Graphics4::swapBuffers();
}

#ifdef __cplusplus
extern "C" {
#endif

void Kore_System__updateWithSystemObject(
	// KoreSystemObject* systemObject,
	KoreSystemObject systemObject,
	// void (*systemCallback)(KoreSystemObject*))
	void (*systemCallback)(KoreSystemObject))
{
	_koreSystemObject = systemObject;
	_koreSystemObjectCallback = systemCallback;
	Kore::System::setCallback(koreSystemObjectUpdateCallback);
}

void Kore_System_init(const char* name, int width, int height) {
	Kore::System::init(name, width, height);
}

int Kore_System_currentDevice() {
	return Kore::System::currentDevice();
}

int Kore_System_initWindow(WS_Kore_WindowOptions* options) {
	Kore::WindowOptions windowOptions;
	Kore::RendererOptions rendererOptions;

	windowOptions.title = options->title;
	windowOptions.width = options->width;
	windowOptions.height = options->height;
	windowOptions.x = options->x;
	windowOptions.y = options->y;
	windowOptions.targetDisplay = options->targetDisplay;
	windowOptions.vSync = options->vSync;
	windowOptions.resizable = options->resizable;
	windowOptions.maximizable = options->maximizable;
	windowOptions.minimizable = options->minimizable;
	windowOptions.mode = (Kore::WindowMode)options->mode;
	windowOptions.showWindow = options->showWindow;

	rendererOptions.textureFormat = options->rendererOptions.textureFormat;
	rendererOptions.depthBufferBits = options->rendererOptions.depthBufferBits;
	rendererOptions.stencilBufferBits = options->rendererOptions.stencilBufferBits;
	rendererOptions.antialiasing = options->rendererOptions.antialiasing;
	windowOptions.rendererOptions = rendererOptions;

	return Kore::System::initWindow(windowOptions);
}

void Kore_System_destroyWindow(int id) {
	Kore::System::destroyWindow(id);
}

void* Kore_System_windowHandle(int windowId) {
	return Kore::System::windowHandle(windowId);
}

int Kore_System_windowWidth(int id) {
	return Kore::System::windowWidth(id);
}

int Kore_System_windowHeight(int id) {
	return Kore::System::windowHeight(id);
}

int Kore_System_windowCount() {
	return Kore::System::windowCount();
}

int Kore_System_screenDpi() {
	return Kore::System::screenDpi();
}

void Kore_System_changeResolution(int width, int height, bool fullscreen) {
	Kore::System::changeResolution(width, height, fullscreen);
}

bool Kore_System_handleMessages() {
	return Kore::System::handleMessages();
}

// TODO: Kore::System::mousePos not defined for Linux backend?
// vec2i Kore_System_mousePos() {
// 	return Kore::System::mousePos();
// }

void Kore_System_showKeyboard() {
	Kore::System::showKeyboard();
}

void Kore_System_hideKeyboard() {
	Kore::System::hideKeyboard();
}

// TODO: Kore::System::showsKeyboard not defined for Linux backend?
// bool Kore_System_showsKeyboard() {
// 	return Kore::System::showsKeyboard();
// }

void Kore_System_loadURL(const char* url) {
	Kore::System::loadURL(url);
}

int Kore_System_desktopWidth() {
	return Kore::System::desktopWidth();
}

int Kore_System_desktopHeight() {
	return Kore::System::desktopHeight();
}

const char* Kore_System_systemId() {
	return Kore::System::systemId();
}

void Kore_System_setTitle(const char* title) {
	Kore::System::setTitle(title);
}

const char* Kore_System_savePath() {
	return Kore::System::savePath();
}

const char** Kore_System_videoFormats() {
	return Kore::System::videoFormats();
}

void Kore_System_showWindow() {
	Kore::System::showWindow();
}

void Kore_System_swapBuffers(int contextId) {
	Kore::System::swapBuffers(contextId);
}

void Kore_System_makeCurrent(int contextId) {
	Kore::System::makeCurrent(contextId);
}

void Kore_System_clearCurrent() {
	Kore::System::clearCurrent();
}

double Kore_System_frequency() {
	return Kore::System::frequency();
}

ticks Kore_System_timestamp() {
	return Kore::System::timestamp();
}

double Kore_System_time() {
	return Kore::System::time();
}

void Kore_System_setName(const char* name) {
	Kore::System::setName(name);
}

const char* Kore_System_name() {
	return Kore::System::name();
}

bool Kore_System_hasShowWindowFlag() {
	return Kore::System::hasShowWindowFlag();
}

void Kore_System_setShowWindowFlag(bool value) {
	Kore::System::setShowWindowFlag(value);
}

int Kore_System_simpleSetup(int argc, char* argv[], int width, int height,
							int antialiasing, WE_Kore_WindowMode mode,
							const char* title, bool showWindow) {
	// mode = (Kore::WindowMode)mode;
	return Kore::System::simpleSetup(argc, argv, width, height, antialiasing,
									 (Kore::WindowMode)mode, title, showWindow);
}

void Kore_System_setup() {
	Kore::System::setup();
}

void Kore_System_start() {
	Kore::System::start();
}

void Kore_System_stop() {
	Kore::System::stop();
}

void Kore_System__shutdown() {
	Kore::System::_shutdown();
}

bool Kore_System_isFullscreen() {
	return Kore::System::isFullscreen();
}

void Kore_System_setCallback(void (*value)()) {
	Kore::System::setCallback(value);
}

void Kore_System_setForegroundCallback(void (*value)()) {
	Kore::System::setForegroundCallback(value);
}

void Kore_System_setResumeCallback(void (*value)()) {
	Kore::System::setResumeCallback(value);
}

void Kore_System_setPauseCallback(void (*value)()) {
	Kore::System::setPauseCallback(value);
}

void Kore_System_setBackgroundCallback(void (*value)()) {
	Kore::System::setBackgroundCallback(value);
}

void Kore_System_setShutdownCallback(void (*value)()) {
	Kore::System::setShutdownCallback(value);
}

void Kore_System_setOrientationCallback(void (*value)(WE_Kore_Orientation)) {
	// Store the callback and use another function in its place to translate
	// between the enum values of Kore::Orientation and its wrapping as defined
	// by WE_Kore_Orientation.
	wrapped_setOrientationCallback = value;
	Kore::System::setOrientationCallback(setOrientationCallback_translator);
}

void Kore_System_setDropFilesCallback(void (*value)(wchar_t*)) {
	Kore::System::setDropFilesCallback(value);
}

void Kore_System_setKeepScreenOn(bool on) {
	Kore::System::setKeepScreenOn(on);
}

void Kore_System_callback() {
	Kore::System::callback();
}

void Kore_System_foregroundCallback() {
	Kore::System::foregroundCallback();
}

void Kore_System_resumeCallback() {
	Kore::System::resumeCallback();
}

void Kore_System_pauseCallback() {
	Kore::System::pauseCallback();
}

void Kore_System_backgroundCallback() {
	Kore::System::backgroundCallback();
}

void Kore_System_shutdownCallback() {
	Kore::System::shutdownCallback();
}

void Kore_System_orientationCallback(WE_Kore_Orientation orientation) {
	Kore::System::orientationCallback((Kore::Orientation)orientation);
}

void Kore_System_dropFilesCallback(wchar_t* filePath) {
	Kore::System::dropFilesCallback(filePath);
}

#ifdef __cplusplus
}
#endif
