#pragma once

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Core/Thread.h>

using namespace Urho3D;

namespace io::atome::wavelet {
	class Wavelet : public Object
	{
		URHO3D_OBJECT(Wavelet, Object);

	public:
		Wavelet(SharedPtr<Context> context, void* parent, int width, int height);
		~Wavelet();

		virtual void RunFrame();

	private:
		void HandleFrequency(StringHash eventType, VariantMap& eventData);
		void CreateLogo();

		SharedPtr<Engine> engine_;
		int width_;
		int height_;

		SharedPtr<Sprite> logoSprite_;
	};

	class WaveletThread : public Thread
	{
	public:
		WaveletThread(void* parent, int width, int height);
		~WaveletThread() override;

	private:
		void ThreadFunction();

		void* parent_;
		SharedPtr<Context> context_;
		SharedPtr<Wavelet> wavelet_;

		int width_;
		int height_;
	};
} // namespace