#include "sbpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Saber
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
