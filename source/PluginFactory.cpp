#include "WaveletProcessor.h"
#include "WaveletController.h"
#include "Constants.h"

#include "public.sdk/source/main/pluginfactory.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

using namespace io::atome::wavelet;

BEGIN_FACTORY_DEF(COMPANY_NAME,
	COMPANY_URL,
	COMPANY_EMAIL)

	DEF_CLASS2(INLINE_UID_FROM_FUID(ProcessorUID),
		PClassInfo::kManyInstances,
		kVstAudioEffectClass,
		PLUGIN_NAME,
		Vst::kDistributable,
		Vst::PlugType::kFxInstrument,
		VERSION,
		kVstVersionString,
		WaveletProcessor::createInstance)

	DEF_CLASS2(INLINE_UID_FROM_FUID(ControllerUID),
		PClassInfo::kManyInstances,
		kVstComponentControllerClass,
		PLUGIN_NAME,
		0,
		"",
		VERSION,
		kVstVersionString,
		WaveletController::createInstance)
END_FACTORY