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
			unsigned int index;
			unsigned int count;
			unsigned int type;
			unsigned int size;

		};
	public:
		VertexArrayGL();
		virtual ~VertexArrayGL();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		// virtual VertexArray* Create(VertexBuffer*, IndexBuffer*);

		// template<typename T>
		// void Push(unsigned int count);
		// template<>
		virtual void AddLayout(unsigned int count) override;

		virtual void Push() override;


	private:

		unsigned int m_ID;
		unsigned int m_FullCount = 0;
		unsigned int m_indexCounter = 0;

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