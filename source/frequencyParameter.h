#pragma once

#include "public.sdk/source/vst/vstparameters.h"
#include "pluginterfaces/base/ftypes.h"

namespace io::atome::wavelet {
	class FrequencyParameter : public Steinberg::Vst::Parameter
	{
	public:
		FrequencyParameter(Steinberg::int32 flags, Steinberg::int32 id);

		void toString(Steinberg::Vst::ParamValue normValue, Steinberg::Vst::String128 string) const SMTG_OVERRIDE;
		bool fromString(const Steinberg::Vst::TChar* string, Steinberg::Vst::ParamValue& normValue) const SMTG_OVERRIDE;
	};
}