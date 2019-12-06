#pragma once

#include <pluginterfaces\gui\iplugview.h>

#include "EveView.h"

namespace io::atome::wavelet {
	class WaveletView : public Steinberg::IPlugView
	{

	public:
		WaveletView(FrequencyParameter* frequencyParameter);
		~WaveletView();

		Steinberg::tresult PLUGIN_API queryInterface(const Steinberg::TUID _iid, void** obj) SMTG_OVERRIDE;
		virtual Steinberg::uint32 PLUGIN_API addRef() SMTG_OVERRIDE;
		virtual Steinberg::uint32 PLUGIN_API release() SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API isPlatformTypeSupported(Steinberg::FIDString type) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API attached(void* parent, Steinberg::FIDString type) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API removed() SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API onWheel(float distance) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API onKeyDown(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API onKeyUp(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API getSize(Steinberg::ViewRect* size) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API onSize(Steinberg::ViewRect* newSize) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API onFocus(Steinberg::TBool state) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API setFrame(Steinberg::IPlugFrame* frame) SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API canResize() SMTG_OVERRIDE;
		virtual Steinberg::tresult PLUGIN_API checkSizeConstraint(Steinberg::ViewRect* rect) SMTG_OVERRIDE;

	private:
		Steinberg::uint32 nbRef_;
		Steinberg::IPlugFrame* frame_;
		EveViewThread* eveViewThread_;
		FrequencyParameter* frequencyParameter_;

		int width_;
		int height_;
	};
}
