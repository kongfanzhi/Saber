#pragma once
#include "Core.h"
#include "Saber/LayerStack.h"
#include "Saber/Events/Event.h"
#include "Saber/Events/ApplicationEvent.h"

#include "Window.h"
#include "ImGui/ImGuiLayer.h"

#include "Saber/Core/Timestep.h"

namespace Saber
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}
