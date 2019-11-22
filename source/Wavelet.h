#pragma once

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Core/Thread.h>

namespace io::atome::wavelet {
	class Wavelet : public Urho3D::Object
	{
		URHO3D_OBJECT(Wavelet, Urho3D::Object);

	public:
		Wavelet(Urho3D::SharedPtr<Urho3D::Context> context, void* parent, int width, int height);
		~Wavelet();

		virtual void RunFrame();

	private:
		void HandleFrequency(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
		void CreateLogo();

		Urho3D::SharedPtr<Urho3D::Engine> engine_;
		int width_;
		int height_;

		Urho3D::SharedPtr<Urho3D::Sprite> logoSprite_;
	};

	class WaveletThread : public Urho3D::Thread
	{
	public:
		WaveletThread(void* parent, int width, int height);
		~WaveletThread() override;

	private:
		void ThreadFunction();

		void* parent_;
		Urho3D::SharedPtr<Urho3D::Context> context_;
		Urho3D::SharedPtr<Wavelet> wavelet_;

		int width_;
		int height_;
	};
} // namespace