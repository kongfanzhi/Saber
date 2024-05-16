#pragma once

#include "Saber/Layer.h"

namespace Saber
{
    class ImGuiLayer:public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    };
}


