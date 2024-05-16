#include "sbpch.h"
#include "ImGuiLayer.h"

namespace Saber
{
    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnUpdate()
    {
        Layer::OnUpdate();
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        Layer::OnEvent(event);
    }
}
