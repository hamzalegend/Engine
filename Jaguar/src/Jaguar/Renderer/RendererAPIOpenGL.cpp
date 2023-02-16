#include "RendererAPIOpenGL.h"

#include "GL/glew.h"
#include <Jaguar/Log/log.h>



namespace Jaguar
{
	void RendererAPIOpenGL::Init()
	{
		if (glewInit() != GLEW_OK)
		{
			JR_CORE_ERROR("Could Not Initialize The OpenGL Context")
				return;
		}
	}
	void RendererAPIOpenGL::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void RendererAPIOpenGL::SetClearColor(Vector4 color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}
	
	void RendererAPIOpenGL::DrawIndexed(int count)
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	}
}
