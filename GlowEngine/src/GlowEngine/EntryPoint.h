#pragma once

//#include "Log.h"

#ifdef GWE_PLATFORM_WINDOWS

extern Glow::Application* Glow::CreateApplication();

int main(int argc, char** argv)
{
	Glow::Log::Init();
	GWE_CORE_INFO("Initialized Core Logger");
	GWE_CORE_WARN("Initialized Client Logger");

	auto app = Glow::CreateApplication();
	app->Run();
	delete app;
}

#endif // GWE_PLATFORM_WINDOWS
