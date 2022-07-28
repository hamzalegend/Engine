#pragma once

#include "Core.h"
namespace Jaguar {
	class JAGUAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// to be defined in client
	Application* CreateApplication();
}