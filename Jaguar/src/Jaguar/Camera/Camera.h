#pragma once

#include "Jaguar/Math.h"
#include "GL/glew.h"
#include <GLFW/glfw3.h>

namespace Jaguar
{

	class Camera
	{
	public:
		Camera(Vector2 windowdimentions , float fov = 45);
		~Camera();

		
	
		void SetFOV(float fov);

		Mat4 GetProjectionMatrix();
		Mat4 GetViewMatrix();

		Vector3 Position = Vector3(0.0f, 0.0f, -3.0f);
		Vector3 Rotation = Vector3(0.0f, 0.0f, 0.0f);

		Vector3	Front = glm::vec3(0.0f, 0.0f, -1.0f);
		Vector3 Right = glm::normalize(glm::cross(Front, WorldUp));
		Vector3 Up = glm::cross(Right, Front);
		
	private:
		Vector2 m_WindowDimetions;

		float FOV;

		float m_NearPlane = 0.1f;
		float m_FarPlane = 100.0f;


		Mat4 m_projection;
		Mat4 m_view;

		Vector3 WorldUp = Vector3(0.0f, 1.0f, 0.0f);




		// Vector3 m_Target;
		// Vector3 m_CameraDirection = glm::normalize(Position - m_Target);


	
	};

}

