#include "Application.h"

#include "GEWS/Events/ApplicationEvent.h"
#include "GEWS/Log.h"

namespace GEWS
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
		GEWS_TRACE(e);
		while (true);
	}
}
