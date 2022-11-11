#pragma once
#include "../Texture.h"
#include "../Shader.h"
#include "Jaguar/Core.h"
namespace Jaguar {

	class TextureGL : public Texture
	{
	public:
		
		TextureGL(std::string path, int Index, bool istransparent);
		~TextureGL();

		virtual int GetIndex() const override { return m_Index; };	

		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		unsigned int m_ID;
		std::string m_path;
		unsigned int m_Index;

	};

}

