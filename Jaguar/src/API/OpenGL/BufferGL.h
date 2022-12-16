#pragma once
#include "GL/glew.h"
#include "../Buffer.h"

namespace Jaguar
{
	class VertexBufferGL : public VertexBuffer
	{
	public:
		VertexBufferGL(const void* data, unsigned int size);
		virtual ~VertexBufferGL();

		virtual void Bind() const override;
		virtual void UnBind() const override;
	
	private:
		unsigned int m_ID;
	};

	class VertexArrayGL : public VertexArray
	{
		struct VertexLayout
		{
		public:
			unsigned int count;
			unsigned int type;
			bool normalized;
		};
	public:
		VertexArrayGL();
		virtual ~VertexArrayGL();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddLayout(unsigned int count) override;

		virtual void Push() override;
	private:
		unsigned int m_ID;
		unsigned int m_stride = 0;

		std::vector<VertexLayout> layouts;
	};


	class IndexBufferGL : public IndexBuffer
	{
	public:
		IndexBufferGL(const unsigned int* data, unsigned int count);
		virtual ~IndexBufferGL();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		inline unsigned int getCount() const { return m_Count; }

	private:
		
		unsigned int m_ID;
		unsigned int m_Count;

	};




}