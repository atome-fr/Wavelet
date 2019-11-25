#include "WaveletProcessor.h"
#include "Application.h"
#include "Constants.h"

#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"

#include <stdio.h>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

#include "base/source/fstreamer.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace io::atome::wavelet {
	FUnknown* WaveletProcessor::createInstance(void* context)
	{
		return (IAudioProcessor*) new WaveletProcessor;
	}

	//FIXME: Get sample rate from DAW.
	WaveletProcessor::WaveletProcessor() : sampleRate_(22050), frequency_(440.f)
	{
		setControllerClass(io::atome::wavelet::ControllerUID);
	}

	tresult PLUGIN_API WaveletProcessor::initialize(FUnknown* context)
	{
		tresult result = AudioEffect::initialize(context);
		if (result == kResultTrue)
		{
			addAudioOutput(STR16("Audio Output"), SpeakerArr::kStereo);
		}
		return result;
	}

	tresult PLUGIN_API WaveletProcessor::setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
	{
		// We only support one stereo output stereo bus.
		if (numIns == 0 && numOuts == 1 && outputs[0] == SpeakerArr::kStereo)
		{
			return AudioEffect::setBusArrangements(inputs, numIns, outputs, numOuts);
		}
		return kResultFalse;
	}

	tresult PLUGIN_API WaveletProcessor::canProcessSampleSize(int32 symbolicSampleSize)
	{
		if (symbolicSampleSize == kSample32 || symbolicSampleSize == kSample64)
		{
			return kResultTrue;
		}
		return kResultFalse;
	}

	tresult PLUGIN_API WaveletProcessor::setState(IBStream* state)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletProcessor::getState(IBStream* state)
	{
		return kResultOk;
	}

	tresult PLUGIN_API WaveletProcessor::process(ProcessData& data)
	{
		tresult result = kResultOk;

		if (data.numSamples > 0) {
			if (data.symbolicSampleSize == kSample32) {
				result = processGeneric<Sample32>(data.outputs[0], data.numSamples, data.inputParameterChanges);
			}
			else {
				result = processGeneric<Sample64>(data.outputs[0], data.numSamples, data.inputParameterChanges);
			}
		}

		return result;
	}

	template<typename SampleType> tresult WaveletProcessor::processGeneric(AudioBusBuffers& output, int32 numSamples, IParameterChanges* inputParameterChanges)
	{
		if (inputParameterChanges)
		{
			int32 parametersCount = inputParameterChanges->getParameterCount();
			for (int32 index = 0; index < parametersCount; index++)
			{
				IParamValueQueue* paramValueQueue = inputParameterChanges->getParameterData(index);
				if (paramValueQueue)
				{
					ParamValue paramValue;
					int32 sampleOffset;
					int32 pointsCount = paramValueQueue->getPointCount();
					switch (paramValueQueue->getParameterId())
					{
					case kFrequencyId:
						if (paramValueQueue->getPoint(pointsCount - 1, sampleOffset, paramValue) == kResultTrue) {
							frequency_ = paramValue * 1000;
						}
						break;
					}
				}
			}
		}

		SampleType** outputSamples = getBuffer<SampleType>(output);

		// Stereo, so loop on 2 channels.
		for (int32 i = 0; i < 2; i++)
		{
			SampleType* ptrOutputSample = outputSamples[i];

			for (int j = 0; j < numSamples; ++j)
			{
				(*ptrOutputSample++) = 32760 * sin(((2. * M_PI * frequency_) / sampleRate_) * j);
			}
		}

		return kResultOk;
	}

	template<> Sample32** WaveletProcessor::getBuffer(AudioBusBuffers& buffer)
	{
		return buffer.channelBuffers32;
	}

	template<> Sample64** WaveletProcessor::getBuffer(AudioBusBuffers& buffer)
	{
		return buffer.channelBuffers64;
	}
} // namespace
