#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace io::atome::wavelet {
	class Processor : public AudioEffect
	{
	public:
		static FUnknown* createInstance(void* context);

		Processor();

		tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;

		tresult PLUGIN_API setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts) SMTG_OVERRIDE;
		tresult PLUGIN_API canProcessSampleSize(int32 symbolicSampleSize) SMTG_OVERRIDE;

		tresult PLUGIN_API setState(IBStream* state) SMTG_OVERRIDE;
		tresult PLUGIN_API getState(IBStream* state) SMTG_OVERRIDE;

		tresult PLUGIN_API process(ProcessData& data) SMTG_OVERRIDE;

	private:
		template<typename SampleType> tresult processGeneric(AudioBusBuffers& output, int32 numSamples, IParameterChanges* inputParameterChanges);

		template<typename SampleType> SampleType** getBuffer(AudioBusBuffers& buffer);
		template<> Sample32** getBuffer(AudioBusBuffers& buffer);
		template<> Sample64** getBuffer(AudioBusBuffers& buffer);

		unsigned int sampleRate_;
		float frequency_;
	};
} // namespace
