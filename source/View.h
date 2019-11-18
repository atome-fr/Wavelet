#pragma once

#include <Windows.h>

#include "pluginterfaces\gui\iplugview.h"

#include "Wavelet.h"

using namespace Steinberg;

namespace io::atome::wavelet {
	class View : public IPlugView
	{

	public:
		View();
		~View();

		tresult PLUGIN_API queryInterface(const TUID _iid, void** obj) SMTG_OVERRIDE;
		virtual uint32 PLUGIN_API addRef() SMTG_OVERRIDE;
		virtual uint32 PLUGIN_API release() SMTG_OVERRIDE;
		virtual tresult PLUGIN_API isPlatformTypeSupported(FIDString type) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API attached(void* parent, FIDString type) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API removed() SMTG_OVERRIDE;
		virtual tresult PLUGIN_API onWheel(float distance) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API onKeyDown(char16 key, int16 keyCode, int16 modifiers) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API onKeyUp(char16 key, int16 keyCode, int16 modifiers) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API getSize(ViewRect* size) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API onSize(ViewRect* newSize) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API onFocus(TBool state) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API setFrame(IPlugFrame* frame) SMTG_OVERRIDE;
		virtual tresult PLUGIN_API canResize() SMTG_OVERRIDE;
		virtual tresult PLUGIN_API checkSizeConstraint(ViewRect* rect) SMTG_OVERRIDE;

	private:
		uint32 nbRef_;
		IPlugFrame* frame_;
		WaveletThread* waveletThread_;

		int width_;
		int height_;
	};
}

