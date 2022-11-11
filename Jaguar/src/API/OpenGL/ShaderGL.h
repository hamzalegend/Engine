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

		virtual void SetUniformMat4(const char* name, Mat4 Value) override;
		virtual void SetUniform1i(const char* name, int Value) override;
		virtual void SetUniform1f(const char* name, float Value) override;
		virtual void SetUniform2f(const char* name, Vector2 Value) override;
		virtual void SetUniform3f(const char* name, Vector3 Value) override;

	private:
		unsigned int m_ID;
		const char* vCode;
		const char* fCode;

		std::string Read(std::string path);
		void Compile() ;


	};
}