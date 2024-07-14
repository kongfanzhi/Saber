#pragma once

#include "Saber/Layer.h"
#include "Saber/Events/ApplicationEvent.h"
#include "Saber/Events/KeyEvent.h"
#include "Saber/Events/MouseEvent.h"

namespace Saber
{
    class SABER_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float m_Time = 0.0f;
    };
}
