#include "sbpch.h"
#include "Application.h"

#include "Saber/Events/ApplicationEvent.h"
#include "Saber/Log.h"


namespace Saber
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SB_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SB_TRACE(e);
		}

		while (1)
		{

		}
	}

}