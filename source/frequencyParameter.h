#pragma once

#include "public.sdk/source/vst/vstparameters.h"
#include "pluginterfaces/base/ftypes.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace io::atome::wavelet {
	class FrequencyParameter : public Parameter
	{
	public:
		FrequencyParameter(int32 flags, int32 id);

		void toString(ParamValue normValue, String128 string) const SMTG_OVERRIDE;
		bool fromString(const TChar* string, ParamValue& normValue) const SMTG_OVERRIDE;
	};
}