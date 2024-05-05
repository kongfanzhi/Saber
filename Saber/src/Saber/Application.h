#pragma once
#include "Core.h"

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


