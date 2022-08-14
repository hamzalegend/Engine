#include "Buffer.h"
#include "OpenGL/BufferGL.h"
int api = 1;

namespace Jaguar {

	VertexBuffer* VertexBuffer::Create(const void* data, unsigned int size)
	{
		switch (api)
		{
		case(1):
			return new VertexBufferGL(data, size);
		default:
			break;
		}
	}

	IndexBuffer* IndexBuffer::Create(const unsigned int* data, unsigned int count)
	{
		switch (api)
		{
		case(1):
			return new IndexBufferGL(data, count);
		default:
			break;
		}
	}


}

