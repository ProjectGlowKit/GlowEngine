#pragma once

#ifdef GWE_PLATFORM_WINDOWS

extern Glow::Application* Glow::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Glow::CreateApplication();
	app->Run();
	delete app;
}

#endif // GWE_PLATFORM_WINDOWS
