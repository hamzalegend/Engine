#pragma once
#include <vector>
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

		virtual inline unsigned int getCount() const = 0;
	private:

	};

	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		
		static VertexArray* Create();

		virtual void AddLayout(unsigned int count) = 0;
		virtual void Push() = 0;

		virtual void SetIndexBuffer(IndexBuffer* ib) = 0;
		virtual IndexBuffer* GetIndexBuffer() = 0;
		

	private:

	};



}
