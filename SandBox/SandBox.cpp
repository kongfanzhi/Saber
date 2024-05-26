#include "Saber.h"
//#include "Saber/ImGui/ImGuiLayer.h"

class ExampleLayer : public Saber::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Saber::Input::IsKeyPressed(SB_KEY_TAB))
			SB_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Saber::Event& event) override
	{
		if (event.GetEventType() == Saber::EventType::KeyPressed)
		{
			Saber::KeyPressedEvent& e = (Saber::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SB_KEY_TAB)
				SB_TRACE("Tab key is pressed (event)!");
			SB_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class SandBox :public Saber::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Saber::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

Saber::Application* Saber::CreateApplication()
{
	return new SandBox();
}