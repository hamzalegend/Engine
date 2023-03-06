#pragma once

#include "Jaguar/Math.h"

#include "Jaguar/Renderer/Mesh.h"
#include "Jaguar/Camera/Camera.h"

#include <string>

namespace Jaguar
{
	struct TransformComponent
	{
		Mat4 Transform;
		TransformComponent() = default;
		TransformComponent(Mat4 transform)
			:Transform(transform)
		{};

		Vector3 Position = { 0, 0, 0 };
		Vector3 Rotation = { 0, 0, 0 };
		Vector3 Scale = { 0, 0, 0 };
		operator glm::mat4& () { return Transform; }

		void Update()
		{
			Transform = Mat4(1.0);
			Transform = glm::translate(Transform, Position);
		
			Transform = glm::rotate(Transform, Rotation.x, Vector3(1, 0, 0));
			Transform = glm::rotate(Transform, Rotation.y, Vector3(0, 1, 0));
			Transform = glm::rotate(Transform, Rotation.z, Vector3(0, 0, 1));
		
			Transform = glm::scale(Transform, Scale);
		}
	};

	struct TagComponent
	{
		std::string name;
		operator std::string& () { return name; }
	};

	struct MeshRendererComponent
	{
		Mesh mesh;
		// Vector4 color;
	};

	struct CameraComponent
	{
		bool Primary = true;
		Camera* cam;
	};
}