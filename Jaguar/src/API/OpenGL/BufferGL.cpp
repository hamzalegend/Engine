#include "BufferGL.h"
#include "../../Jaguar/Log/log.h"

namespace Jaguar{
	
	//========================[VertexBuffer]=====================
	VertexBufferGL::VertexBufferGL(const void* data, unsigned int size)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID); // (Bind())
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	
		JR_CORE_TRACE("Created OpenGL VertexBuffer...");
	}
	
	VertexBufferGL::~VertexBufferGL()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBufferGL::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VertexBufferGL::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	

	//========================[IndexBuffer]=====================
	IndexBufferGL::IndexBufferGL(const unsigned int* data, unsigned int count)
		:m_Count(count)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);

		JR_CORE_TRACE("Created OpenGL IndeBuffer...");
	}

	IndexBufferGL::~IndexBufferGL()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void IndexBufferGL::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void IndexBufferGL::UnBind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}