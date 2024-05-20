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
		SB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Saber::Event& event) override
	{
		SB_TRACE("{0}", event);
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