#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"

namespace io::atome::wavelet {
	class WaveletProcessor : public Steinberg::Vst::AudioEffect
	{
	public:
		static Steinberg::FUnknown* createInstance(void* context);

		WaveletProcessor();

		Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) SMTG_OVERRIDE;

		Steinberg::tresult PLUGIN_API setBusArrangements(Steinberg::Vst::SpeakerArrangement* inputs, Steinberg::int32 numIns, Steinberg::Vst::SpeakerArrangement* outputs, Steinberg::int32 numOuts) SMTG_OVERRIDE;
		Steinberg::tresult PLUGIN_API canProcessSampleSize(Steinberg::int32 symbolicSampleSize) SMTG_OVERRIDE;

		Steinberg::tresult PLUGIN_API setState(Steinberg::IBStream* state) SMTG_OVERRIDE;
		Steinberg::tresult PLUGIN_API getState(Steinberg::IBStream* state) SMTG_OVERRIDE;

		Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data) SMTG_OVERRIDE;

	private:
		template<typename SampleType> Steinberg::tresult processGeneric(Steinberg::Vst::AudioBusBuffers& output, Steinberg::int32 numSamples, Steinberg::Vst::IParameterChanges* inputParameterChanges);

		template<typename SampleType> SampleType** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);
		template<> Steinberg::Vst::Sample32** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);
		template<> Steinberg::Vst::Sample64** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);

		unsigned int sampleRate_;
		float frequency_;
	};
} // namespace
