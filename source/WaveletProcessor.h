#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "pluginterfaces/vst/ivstevents.h"

#include <q/synth/sin.hpp>

#include <map>

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
		template<typename SampleType> Steinberg::tresult processSamples(Steinberg::Vst::AudioBusBuffers& output, Steinberg::int32 numSamples);

		template<typename SampleType> SampleType** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);
		template<> Steinberg::Vst::Sample32** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);
		template<> Steinberg::Vst::Sample64** getBuffer(Steinberg::Vst::AudioBusBuffers& buffer);

		void processParameterChanges(Steinberg::Vst::IParameterChanges* inputParameterChanges);
		void processEvents(Steinberg::Vst::IEventList* events);

		float frequency_;
		bool bypass_;

		std::map<Steinberg::int32, Steinberg::Vst::NoteOnEvent> notes_;

		cycfi::q::phase_iterator phase_;

	};
} // namespace
