#pragma once
#include<string>
#include "../../Jaguar/Core.h"
#include "../Shader.h"

namespace Jaguar {

	class ShaderGL : public Shader
	{
	public:
		ShaderGL(const char* vertexPath, const char* fragmentPath);
		~ShaderGL();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetUniform(Mat4 Value) override;

	private:
		unsigned int m_ID;
		const char* vCode;
		const char* fCode;

		std::string Read(std::string path);
		void Compile() ;


	};
}