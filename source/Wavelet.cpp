#include "Application.h"
#include "Wavelet.h"

#include <windows.h>

#include <Urho3D/Core/Context.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/ScrollView.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/Input/Input.h>

#include <SDL/SDL.h>

#include <sstream>


using namespace std;

extern "C" LRESULT CALLBACK WIN_WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace io::atome::wavelet {
	Wavelet::Wavelet(SharedPtr<Context> context, void* parent, int width, int height) :
		Object(context),
		engine_(nullptr),
		logoSprite_(nullptr),
		width_(width),
		height_(height)
	{
		Urho3D::VariantMap engineParameters_;

		//Urho manages the external window but VST don't want to. So, we need to create an intermediate window.
		HWND intermediateWindow = CreateWindow(
			L"Static",
			NULL,
			WS_CHILD | WS_VISIBLE,
			0, 0, width_, height_,
			(HWND)parent,
			NULL,
			(HINSTANCE) moduleHandle,
			NULL
		);

		//TODO: Hack; should be fixed. Urho do not seem to set SDL WNDPROC on parent window, so, set it ourself.
		SetWindowLongPtr(intermediateWindow, GWLP_WNDPROC, (LONG_PTR)WIN_WindowProc);

		engineParameters_[EP_EXTERNAL_WINDOW] = intermediateWindow;
		engineParameters_[EP_FULL_SCREEN] = false;
		engineParameters_[EP_RESOURCE_PREFIX_PATHS] = contentPath.c_str();

		engine_ = new Urho3D::Engine(context_);
		engine_->Initialize(engineParameters_);

		Input* input = GetSubsystem<Input>();
		input->SetMouseVisible(true);

		ResourceCache* cache = GetSubsystem<ResourceCache>();

		UI* ui = GetSubsystem<UI>();

		XMLFile* xmlFile = cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
		ui->GetRoot()->SetDefaultStyle(xmlFile);

		Font* font = cache->GetResource<Font>("Fonts/sdf.ttf");

		Button* button = ui->GetRoot()->CreateChild<Button>();
		button->SetPosition(0, 10);
		button->SetStyleAuto();
		button->SetFixedWidth(width);
		button->SetFixedHeight(20);
		SubscribeToEvent(button, E_RELEASED, URHO3D_HANDLER(Wavelet, HandleFrequency));

		Text* buttonText = button->CreateChild<Text>();
		buttonText->SetFont(font, 12);
		buttonText->SetAlignment(HA_CENTER, VA_CENTER);
		buttonText->SetText("Hello Wavelet!");

		Slider* slider = ui->GetRoot()->CreateChild<Slider>();
		slider->SetPosition(0, 30);
		slider->SetStyleAuto();
		slider->SetFixedWidth(width);
		slider->SetFixedHeight(20);
		slider->SetRange(100);
		slider->SetValue(50);
		SubscribeToEvent(slider, E_SLIDERCHANGED, URHO3D_HANDLER(Wavelet, HandleFrequency));
	}

	Wavelet::~Wavelet()
	{
		if (engine_ != nullptr) {
			if (!engine_->IsExiting()) {
				engine_->Exit();
			}

			engine_ = nullptr;
		}
		if (logoSprite_ != nullptr) {
			logoSprite_ = nullptr;
		}
	}

	void Wavelet::RunFrame()
	{
		engine_->RunFrame();
	}

	void Wavelet::HandleFrequency(StringHash eventType, VariantMap& eventData)
	{
		float newFrequency = eventData[SliderChanged::P_VALUE].GetFloat();

		CreateLogo();
	}

	void Wavelet::CreateLogo()
	{
		ResourceCache* cache = GetSubsystem<ResourceCache>();
		Texture2D* logoTexture = cache->GetResource<Texture2D>("Textures/logo.png");

		UI* ui = GetSubsystem<UI>();
		logoSprite_ = ui->GetRoot()->CreateChild<Sprite>();

		logoSprite_->SetTexture(logoTexture);

		int textureWidth = logoTexture->GetWidth();
		int textureHeight = logoTexture->GetHeight();

		logoSprite_->SetSize(460, 400);

		logoSprite_->SetVisible(true);
	}

	WaveletThread::WaveletThread(void* parent, int width, int height) :
		parent_(nullptr),
		context_(nullptr),
		wavelet_(nullptr),
		width_(width),
		height_(height)
	{
		parent_ = parent;
		context_ = new Urho3D::Context();

		wavelet_ = new Wavelet(context_, parent_, width_, height_);
	}

	WaveletThread::~WaveletThread()
	{
		if (wavelet_ != nullptr) {
			wavelet_ = nullptr;
		}
		if (context_ != nullptr) {
			context_ = nullptr;
		}
		if (parent_ != nullptr) {
			parent_ = nullptr;
		}
	}

	void WaveletThread::ThreadFunction()
	{
		SetMainThread();

		while(shouldRun_)
		{
			wavelet_->RunFrame();

			//TODO: Do it the right way...
			Sleep(10);
		}
	}
} // namespace