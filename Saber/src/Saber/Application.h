#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Saber
{
	class SABER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
	};
	Application* CreateApplication();
}


