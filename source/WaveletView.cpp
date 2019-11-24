#include "WaveletView.h"


using namespace Steinberg;

namespace io::atome::wavelet {
	WaveletView::WaveletView(FrequencyParameter* frequencyParameter) :
		nbRef_(0),
		frame_(nullptr),
		eveViewThread_(nullptr),
		width_(800),
		height_(600),
		frequencyParameter_(frequencyParameter)
	{
	}

	WaveletView::~WaveletView()
	{
		if (eveViewThread_ != nullptr) {
			if (eveViewThread_->IsStarted()) {
				eveViewThread_->Stop();
			}

			delete eveViewThread_;
			eveViewThread_ = nullptr;
		}
	}

	tresult PLUGIN_API WaveletView::queryInterface(const TUID _iid, void** obj)
	{
		if (::Steinberg::FUnknownPrivate::iidEqual(iid, WaveletView::iid)) {
			addRef();
			*obj = static_cast<WaveletView*>(this);
			return ::Steinberg::kResultOk;
		}
		return kResultFalse;
	}

	uint32 PLUGIN_API WaveletView::addRef()
	{
		return ++nbRef_;
	}

	uint32 PLUGIN_API WaveletView::release()
	{
		return --nbRef_;
	}

	tresult PLUGIN_API WaveletView::isPlatformTypeSupported(FIDString type)
	{
		if (type = kPlatformStringWin) {
			return kResultTrue;
		}

		return kResultFalse;
	}

	tresult PLUGIN_API WaveletView::attached(void* parent, FIDString type)
	{
		eveViewThread_ = new EveViewThread(parent, width_, height_, frequencyParameter_);
		eveViewThread_->Run();

		return kResultTrue;
	}

	tresult PLUGIN_API WaveletView::removed()
	{
		if (eveViewThread_ != nullptr) {
			if (eveViewThread_->IsStarted()) {
				eveViewThread_->Stop();
			}

			delete eveViewThread_;
			eveViewThread_ = nullptr;
		}

		return kResultTrue;
	}

	tresult PLUGIN_API WaveletView::onWheel(float distance)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::onKeyDown(char16 key, int16 keyCode, int16 modifiers)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::onKeyUp(char16 key, int16 keyCode, int16 modifiers)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::getSize(ViewRect* size)
	{
		size->left = 0;
		size->top = 0;
		size->right = width_;
		size->bottom = height_;

		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::onSize(ViewRect* newSize)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::onFocus(TBool state)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::setFrame(IPlugFrame* frame)
	{
		frame_ = frame;

		return kResultOk;
	}

	tresult PLUGIN_API WaveletView::canResize()
	{
		return kResultFalse;
	}
	
	tresult PLUGIN_API WaveletView::checkSizeConstraint(ViewRect* rect)
	{
		return kResultOk;
	}
} // namespace
