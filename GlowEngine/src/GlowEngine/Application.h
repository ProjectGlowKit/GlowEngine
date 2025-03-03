#pragma once

#include "Core.h"

namespace Glow
{
	class GLOW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Defined in CLIENT
	Application* CreateApplication();
}