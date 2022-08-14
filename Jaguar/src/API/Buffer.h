#pragma once

namespace Jaguar {

	class VertexBuffer
	{
	public:

	

		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static VertexBuffer* Create(const void* data, unsigned int size);

	private:

	};
	class IndexBuffer
	{
	public:



		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static IndexBuffer* Create(const unsigned int* data, unsigned int count);

		// virtual inline unsigned int getCount() const { return m_Count; }
	private:

	};


}
