#pragma once
#include "GLFW/glfw3.h"
#include <string>

namespace Jaguar 
{
	class Window
	{
	public:
		Window();
		void Create(int x, int y, std::string name);
		void Refresh();
		void Resize(int x, int y); // TODO: [Very Important to implement] : glfwSetFramebufferSizeCallback(window.window, framebuffer_size_callback);
		void Destroy();
		~Window();
	
		GLFWwindow* m_window;
		int width;
		int height;
	private:
	};
}