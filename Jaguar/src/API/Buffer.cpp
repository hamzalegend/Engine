#include "Buffer.h"
#include "OpenGL/BufferGL.h"
#include "Jaguar/Renderer/Renderer.h"

namespace Jaguar {

	VertexBuffer* VertexBuffer::Create(const void* data, unsigned int size)
	{
		switch (Renderer::Get_API())
		{
		case(Renderer::API::OpenGL):
			return new VertexBufferGL(data, size);
		default:
			break;
		}
		return nullptr;
	}

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::Get_API())
		{
		case(Renderer::API::OpenGL):
			return new VertexArrayGL();
		default:
			break;
		}
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(const unsigned int* data, unsigned int count)
	{
		switch (Renderer::Get_API())
		{
		case(Renderer::API::OpenGL):
			return new IndexBufferGL(data, count);
		default:
			break;
		}
		return nullptr;
	}


}

