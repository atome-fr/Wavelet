#include "frequencyParameter.h"

#include "pluginterfaces/base/ustring.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace io::atome::wavelet {
	FrequencyParameter::FrequencyParameter(int32 flags, int32 id)
	{
		info.id = id;
		Steinberg::UString(info.title, USTRINGSIZE(info.title)).assign(USTRING("Frequency"));
		Steinberg::UString(info.shortTitle, USTRINGSIZE(info.shortTitle)).assign(USTRING("Freq"));
		Steinberg::UString(info.units, USTRINGSIZE(info.units)).assign(USTRING("Hz"));
		info.stepCount = 0;
		info.defaultNormalizedValue = .44f;
		info.unitId = kRootUnitId;
		info.flags = flags;
	}

	void FrequencyParameter::toString(ParamValue normValue, String128 string) const
	{
		char text[32];
		sprintf(text, "%.4f", normValue);

		Steinberg::UString(string, 128).fromAscii(text);
	}

	bool FrequencyParameter::fromString(const TChar* string, ParamValue& normValue) const
	{
		Steinberg::UString wrapper((TChar*)string, 128);
		wrapper.scanFloat(normValue);

		return true;
	}
}