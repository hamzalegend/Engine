#pragma once
#include<string>
#include "../../Jaguar/Core.h"

namespace Jaguar {

	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void Bind() const;
		void UnBind() const;

	private:
		unsigned int m_ID;
		const char* vCode;
		const char* fCode;

		std::string Read(std::string path);
		void Compile();


	};
}