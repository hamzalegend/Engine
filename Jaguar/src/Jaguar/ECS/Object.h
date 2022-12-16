#pragma once

#include "../Log/log.h"
#include "API/Shader.h"
#include "API/Buffer.h"
#include "API/Texture.h"

#include "../Math.h"
#include <Jaguar/Camera/Camera.h>

namespace Jaguar {

	class Object
	{
	public:
		VertexBuffer* vb;
		IndexBuffer* ib;
		VertexArray* va;
		Shader* shader;
		Texture* texture;

		glm::mat4 model;

		Object();
		~Object();

		void AddTexture(std::string path, int index, int number=0, bool isTransparent = false);

		void Draw();

	private:
		bool m_hasTexture = false;

	};
}