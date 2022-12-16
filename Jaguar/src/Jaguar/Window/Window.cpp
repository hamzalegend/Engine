#include "Window.h"
#include "../Log/log.h"

namespace Jaguar 
{
	Window::Window()
	:m_window(nullptr)
{
	if (!glfwInit())
	{
		JR_CORE_ERROR("Could Not Initialize The Main Window")
		return;
	}
}

	void Window::Create(int x, int y, std::string name)
{
	m_window = glfwCreateWindow(x, y, name.c_str(), NULL, NULL);

	width = x;
	height = y;

	if (!m_window)
	{
		JR_CORE_ERROR("Could Not Initialize The Main Window");
		Destroy();
		return;
	}
	glfwMakeContextCurrent(m_window);
}
	
	void Window::Refresh()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
	
	void Window::Destroy()
{
	glfwTerminate();
}
	
	Window::~Window()
{
	Destroy();
}
}
