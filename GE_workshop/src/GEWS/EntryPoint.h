#pragma once

#ifdef GEWS_PLATFORM_WINDOWS

extern GEWS::Application* GEWS::CreateApplication();

int main(int argc, char** argv)
{
	auto app = GEWS::CreateApplication();
	app->Run();
	delete app;
}

#endif
