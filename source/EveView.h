#pragma once

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Core/Thread.h>
#include <Urho3D/UI/Text.h>

#include "FrequencyParameter.h"

namespace io::atome::wavelet {
	class EveView : public Urho3D::Object
	{
		URHO3D_OBJECT(EveView, Urho3D::Object);

	public:
		EveView(Urho3D::SharedPtr<Urho3D::Context> context, void* parent, int width, int height, FrequencyParameter* frequencyParameter);
		~EveView();

		virtual void RunFrame();

	private:
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

	class EveViewThread : public Urho3D::Thread
	{
	public:
		EveViewThread(void* parent, int width, int height, FrequencyParameter* frequencyParameter);
		~EveViewThread() override;

	private:
		void ThreadFunction();

		Urho3D::SharedPtr<Urho3D::Context> context_;
		Urho3D::SharedPtr<EveView> eveView_;
	};
} // namespace