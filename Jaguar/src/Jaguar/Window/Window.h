#pragma once
#include "gl/glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include <Jaguar/Math.h>

namespace Jaguar 
{
	class Window
	{
	public:
		Window();
		void Create(Vector2 WinDimentions, std::string name);
		void Refresh();
		void Resize(Vector2 WinDimentions); // TODO: [Very Important to implement] : glfwSetFramebufferSizeCallback(window.window, framebuffer_size_callback);
		void Destroy();
		void* GetNative() { return m_window; };
		~Window();
	
		Vector2 Dimentions;
		std::string m_name;
	private:
		GLFWwindow* m_window;
	};
}