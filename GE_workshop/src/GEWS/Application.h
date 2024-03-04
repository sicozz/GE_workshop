#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace GEWS
{
	class GEWS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in the Client
	Application* CreateApplication();
}
