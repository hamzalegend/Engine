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
		layouts.push_back({ Count, GL_FLOAT, false });
		m_stride += Count;
	}

	void VertexArrayGL::Push()
	{	
		if (sizeof(GL_FLOAT) != sizeof(float)) JR_CORE_ERROR("float != GL_FLOAT: please fix asap")

		Bind();
		float offset = 0;
		for (int i = 0; i < layouts.size(); i++)
		{
			const auto& layout = layouts[i];

			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, layout.count, layout.type, GL_FALSE, m_stride * sizeof(layout.type), (void*)((int)offset * sizeof(layout.type)));
			offset += layout.count;
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