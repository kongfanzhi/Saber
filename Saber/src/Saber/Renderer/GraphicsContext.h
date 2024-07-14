#pragma once

namespace Saber
{
    class Graphicscontext
    {
    public:
        virtual void Init() =0;
        virtual void SwapBuffer() =0;
    };
}
