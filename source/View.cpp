#include "View.h"

using namespace Steinberg;

namespace io::atome::wavelet {
	View::View() :
		nbRef_(0),
		frame_(nullptr),
		waveletThread_(nullptr),
		width_(800),
		height_(600)
	{
	}

	View::~View()
	{
		if (waveletThread_ != nullptr) {
			if (waveletThread_->IsStarted()) {
				waveletThread_->Stop();
			}

			delete waveletThread_;
			waveletThread_ = nullptr;
		}
	}

	tresult PLUGIN_API View::queryInterface(const TUID _iid, void** obj)
	{
		if (::Steinberg::FUnknownPrivate::iidEqual(iid, View::iid)) {
			addRef();
			*obj = static_cast<View*>(this);
			return ::Steinberg::kResultOk;
		}
		return kResultFalse;
	}

	uint32 PLUGIN_API View::addRef()
	{
		return ++nbRef_;
	}

	uint32 PLUGIN_API View::release()
	{
		return --nbRef_;
	}

	tresult PLUGIN_API View::isPlatformTypeSupported(FIDString type)
	{
		if (type = kPlatformStringWin) {
			return kResultTrue;
		}

		return kResultFalse;
	}

	tresult PLUGIN_API View::attached(void* parent, FIDString type)
	{
		waveletThread_ = new WaveletThread(parent, width_, height_);
		waveletThread_->Run();

		return kResultTrue;
	}

	tresult PLUGIN_API View::removed()
	{
		if (waveletThread_ != nullptr) {
			if (waveletThread_->IsStarted()) {
				waveletThread_->Stop();
			}

			delete waveletThread_;
			waveletThread_ = nullptr;
		}

		return kResultTrue;
	}

	tresult PLUGIN_API View::onWheel(float distance)
	{
		return kResultOk;
	}

	tresult PLUGIN_API View::onKeyDown(char16 key, int16 keyCode, int16 modifiers)
	{
		return kResultOk;
	}

	tresult PLUGIN_API View::onKeyUp(char16 key, int16 keyCode, int16 modifiers)
	{
		return kResultOk;
	}

	tresult PLUGIN_API View::getSize(ViewRect* size)
	{
		size->left = 0;
		size->top = 0;
		size->right = width_;
		size->bottom = height_;

		return kResultOk;
	}

	tresult PLUGIN_API View::onSize(ViewRect* newSize)
	{
		return kResultOk;
	}

	tresult PLUGIN_API View::onFocus(TBool state)
	{
		return kResultOk;
	}

	tresult PLUGIN_API View::setFrame(IPlugFrame* frame)
	{
		frame_ = frame;

		return kResultOk;
	}

	tresult PLUGIN_API View::canResize()
	{
		return kResultFalse;
	}
	
	tresult PLUGIN_API View::checkSizeConstraint(ViewRect* rect)
	{
		return kResultOk;
	}
} // namespace
