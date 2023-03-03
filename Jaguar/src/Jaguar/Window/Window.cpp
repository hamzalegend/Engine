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
	
	void Window::Create(Vector2 WinDimentions, std::string name)
	{
		Dimentions = WinDimentions;
		m_name = name;
		m_window = glfwCreateWindow(Dimentions.x, Dimentions.y, m_name.c_str(), NULL, NULL);
	
		
		if (!m_window)
		{
			JR_CORE_ERROR("Could Not Initialize The Main Window");
			Destroy();
			return;
		}
		glfwMakeContextCurrent(m_window);
		Resize(Dimentions);
	}
		
	void Window::Refresh()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
		
	
	}

	void Window::Resize(Vector2 WinDimentions)
	{
		Dimentions = WinDimentions;
		glViewport(0, 0, Dimentions.x, Dimentions.y);
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
