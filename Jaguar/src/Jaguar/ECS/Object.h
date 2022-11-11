#pragma once

#include "../Log/log.h"
#include "API/Shader.h"
#include "API/Buffer.h"
#include "API/Texture.h"

#include "../Math.h"

namespace Jaguar {

	class Object
	{
	public:
		Mat4 Transform;
		Vector3 color;

		VertexBuffer* vb;
		IndexBuffer* ib;
		VertexArray* va;
		Shader* shader;
		Texture* texture;


		Object();
		~Object();

		void AddTexture(std::string path, int index, int number=0);

		void Draw();

	private:
		bool hasTexture = false;

	};
}