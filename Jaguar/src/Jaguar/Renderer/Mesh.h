#pragma once

#include "API/Shader.h"
#include "API/Texture.h"

#include "Jaguar/Math.h"

#include <Vector>

namespace Jaguar
{
	struct Mesh
	{
	public:
		std::vector<float> Vertices;
		std::vector<unsigned int> indices;
		Shader* shader;
		Texture* texture;
		// std::vector<Texture> Textures; // TODO :: yeahh...

		Vector4 color;
	};
}