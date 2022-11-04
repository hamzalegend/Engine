#pragma once
#include <string>
#include "Jaguar/Math.h"

namespace Jaguar 
{
	
	class Shader
	{
	public:
		virtual ~Shader() = default;
	
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	
		static Shader* Create(std::string VertexPath, std::string FragmentPath);


		// template <class T>
		virtual void SetUniform(Mat4 Value) = 0;
			

		
	private:
		
		// virtual void Compile();
		// virtual std::string Read(std::string path);
	};

}