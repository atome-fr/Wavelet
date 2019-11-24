#pragma once

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Core/Thread.h>
#include <Urho3D/UI/Text.h>

#include "FrequencyParameter.h"

namespace io::atome::wavelet {
	class Wavelet : public Urho3D::Object
	{
		URHO3D_OBJECT(Wavelet, Urho3D::Object);

	public:
		Wavelet(Urho3D::SharedPtr<Urho3D::Context> context, void* parent, int width, int height, FrequencyParameter* frequencyParameter);
		~Wavelet();

		virtual void RunFrame();

	private:
		void HandleButton(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
		void HandleFrequency(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
		void CreateLogo();
		void updateSliderText();

		Urho3D::SharedPtr<Urho3D::Engine> engine_;
		int width_;
		int height_;
		FrequencyParameter* frequencyParameter_;
		Urho3D::Text* sliderValue_;

		Urho3D::SharedPtr<Urho3D::Sprite> logoSprite_;
	};

	class WaveletThread : public Urho3D::Thread
	{
	public:
		WaveletThread(void* parent, int width, int height, FrequencyParameter* frequencyParameter);
		~WaveletThread() override;

	private:
		void ThreadFunction();

		Urho3D::SharedPtr<Urho3D::Context> context_;
		Urho3D::SharedPtr<Wavelet> wavelet_;
	};
} // namespace