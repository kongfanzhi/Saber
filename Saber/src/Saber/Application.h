#pragma once
#include "Core.h"
#include "Saber/LayerStack.h"
#include "Saber/Events/Event.h"
#include "Saber/Events/ApplicationEvent.h"
#include "Window.h"

namespace Saber
{
	class SABER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	Application* CreateApplication();
}


