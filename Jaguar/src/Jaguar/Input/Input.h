#pragma once

#include "Jaguar/Window/Window.h"
#include "Jaguar/Application.h"
namespace Jaguar
{

	class Input
	{
	public:
		static bool GetKey(int key) { return glfwGetKey(Application::Get().GetWindow()->m_window, key); };
	private:
	};
}