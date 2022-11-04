#pragma once
#include <string>
namespace Jaguar
{
	class Texture
	{
	public:
		virtual ~Texture() = default;


		static Texture* Create(std::string path, int Index, bool isTransparent);

		virtual int GetIndex() const = 0;

	private:

	};

}