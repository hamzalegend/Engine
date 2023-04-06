#include "EditorLayer.h"

namespace Jaguar
{
	EditorLayer::EditorLayer()
	{
	}

	void EditorLayer::OnAttach()
	{
		JR_CORE_INFO("start()");
		{
			e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
			e.AddComponent<MeshRendererComponent>();
			e.GetComponent<MeshRendererComponent>().mesh.Vertices = {
				// positions          // colors                // texture coords
				 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
				-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
			};;
			e.GetComponent<MeshRendererComponent>().mesh.indices = {
		0, 1, 3,
		1, 2, 3,
			};
			e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);


			camera.AddComponent<CameraComponent>();
			camera.GetComponent<CameraComponent>().cam = new Camera();
			Camera* cam = camera.GetComponent<CameraComponent>().cam;
			cam->Transform = &camera.GetComponent<TransformComponent>();
			cam->Transform->Position.z = -4;
		}
	}

	void EditorLayer::OnUpdate(float deltaTime)
	{
		JR_CORE_INFO("Update()");

		// Move Player
		{
			TransformComponent& camTransform = camera.GetComponent<TransformComponent>();
			if (Input::GetKey(GLFW_KEY_D))
			{
				camTransform.Position.x -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_A))
			{
				camTransform.Position.x += deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_W))
			{
				camTransform.Position.z += deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_S))
			{
				camTransform.Position.z -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_E))
			{
				camTransform.Position.y -= deltaTime * 10;
			}
			else if (Input::GetKey(GLFW_KEY_Q))
			{
				camTransform.Position.y += deltaTime * 10;
			}
		}

		scene->OnUpdate(deltaTime);
	}

	void EditorLayer::OnEvent(Jaguar::Event& event)
	{
	}

	EditorLayer::~EditorLayer()
	{
	}

}