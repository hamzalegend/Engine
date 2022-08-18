#pragma once
#include <string>

namespace Jaguar 
{
	
	class Shader
	{
	public:
		virtual ~Shader() = default;
	
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	
		static Shader* Create(std::string VertexPath, std::string FragmentPath);
	
	private:
		
		// virtual void Compile();
		// virtual std::string Read(std::string path);
	};

}