#pragma once

#include "Jaguar/Window/Window.h"
#include "Jaguar/Application.h"
namespace Jaguar
{

	class JAGUAR_API Input
	{
	public:
		static bool GetKey(int key) { return glfwGetKey((GLFWwindow*)Application::Get().GetWindow()->GetNative(), key); };
	private:
	};
}