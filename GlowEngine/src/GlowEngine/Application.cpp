#include "Application.h"

#include "GlowEngine/Events/ApplicationEvent.h"
#include "GlowEngine/Log.h"

namespace Glow
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(800, 600);
		GWE_TRACE(e.ToString());
		GWE_CRIT(e.ToString());

		while (true);
	}
}