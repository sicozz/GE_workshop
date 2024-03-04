#pragma once

#ifdef GEWS_PLATFORM_WINDOWS

extern GEWS::Application* GEWS::CreateApplication();

int main(int argc, char** argv)
{
	GEWS::Log::Init();
	GEWS_CORE_WARN("Initialized Log!");
	int a = 5;
	GEWS_INFO("Hello! Var={0}", a);

	auto app = GEWS::CreateApplication();
	app->Run();
	delete app;
}

#endif
