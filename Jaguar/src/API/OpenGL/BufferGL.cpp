#include "BufferGL.h"
#include "../../Jaguar/Log/log.h"

namespace Jaguar{
	
	//========================[VertexBuffer]=====================
	VertexBufferGL::VertexBufferGL(const void* data, unsigned int size)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID); // (Bind())
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
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

	//========================[VertexArray]=====================

	VertexArrayGL::VertexArrayGL()
		// :vb(vb), ib(ib)
	{
		glGenVertexArrays(1, &m_ID);
	}
	VertexArrayGL::~VertexArrayGL()
	{
		glDeleteVertexArrays(1, &m_ID);
	}
	void VertexArrayGL::Bind() const
	{
		glBindVertexArray(m_ID);
	}
	void VertexArrayGL::UnBind() const
	{
		glBindVertexArray(0);
	}

	void VertexArrayGL::AddLayout(unsigned int Count)
	{
		Bind();
		VertexLayout layout;

		layout.index = m_indexCounter;
		m_indexCounter++;

		layout.count = Count;
		layout.type = GL_FLOAT;
		layout.size = sizeof(float) * Count;
		m_FullCount += Count;
		layouts.push_back(layout);
	}

	void VertexArrayGL::Push()
	{
		for (int i = 0; i < layouts.size(); i++)
		{
			glVertexAttribPointer(layouts[i].index, layouts[i].count, GL_FLOAT, GL_FALSE, sizeof(float) * m_FullCount, 0);
			glEnableVertexAttribArray(layouts[i].index);
		}
	}

	//========================[IndexBuffer]=====================
	IndexBufferGL::IndexBufferGL(const unsigned int* data, unsigned int count)
		:m_Count(count)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
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