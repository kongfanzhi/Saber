#pragma once
#include "Core.h"
#include "Saber/LayerStack.h"
#include "Saber/Events/Event.h"
#include "Saber/Events/ApplicationEvent.h"

#include "Window.h"
#include "ImGui/ImGuiLayer.h"

#include "Saber/Renderer/Shader.h"
#include "Saber/Renderer/Buffer.h"
#include "Saber/Renderer/VertexArray.h"

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

        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;

        std::shared_ptr<Shader> m_BlueShader;
        std::shared_ptr<VertexArray> m_SquareVA;

    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}
