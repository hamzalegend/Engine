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
	private:
		unsigned int m_ID;
		unsigned int m_Index;

	};

}

