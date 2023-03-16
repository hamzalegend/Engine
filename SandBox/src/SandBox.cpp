#include "Engine.h"

namespace Jaguar
{
	std::vector<float> Vertices = {
		// positions          // colors                // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	std::vector<unsigned int> indices = {
		0, 1, 3,
		1, 2, 3,
	};

	class SandBoxLayer : public Layer
	{
	private:

	public:
		Scene* scene = new Scene;
		Entity e = scene->CreateEntity("Square");
		Entity camera = scene->CreateEntity("camera");
		
		SandBoxLayer()
		{
		}

		void OnAttach() override
		{
			JR_CORE_INFO("start()");

			e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
			e.AddComponent<MeshRendererComponent>();
			e.GetComponent<MeshRendererComponent>().mesh.Vertices = Vertices;
			e.GetComponent<MeshRendererComponent>().mesh.indices = indices;
			e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);
			
			
			camera.AddComponent<CameraComponent>();
			camera.GetComponent<CameraComponent>().cam = new Camera();
			Camera* cam = camera.GetComponent<CameraComponent>().cam;
			cam->Transform = &camera.GetComponent<TransformComponent>();
			cam->Transform->Position.z = -4;
		};

		void OnUpdate(float deltaTime) override
		{
			// JR_CORE_INFO("Update()");

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

		virtual void OnEvent(Jaguar::Event& event)
		{
		}

		~SandBoxLayer()
		{
		}

	private:

	};
}

class Sandbox : public Jaguar::Application
{
public:
	Sandbox()
	{
		Jaguar::SandBoxLayer* sandBoxLayer = new Jaguar::SandBoxLayer();
		sandBoxLayer->SetEnabled(true);
		PushLayer(sandBoxLayer);
	};
	~Sandbox()
	{

	};
};


Jaguar::Application* Jaguar::CreateApplication()
{
	return new Sandbox();
}




	// old-new move
	// float cameraSpeed = 5;
	// Vector3 WorldUp = Vector3(0, 1, 0);
	// Vector3 cameraUp = WorldUp;
	// cam->Update(deltaTime);
	// if (glfwGetKey(window.m_window, GLFW_KEY_W) == GLFW_PRESS)
	// 	cam->Position -= cameraSpeed * cam->Forward * deltaTime;
	// if (glfwGetKey(window.m_window, GLFW_KEY_S) == GLFW_PRESS)
	// 	cam->Position += cameraSpeed * cam->Forward * deltaTime;
	// if (glfwGetKey(window.m_window, GLFW_KEY_A) == GLFW_PRESS)
	// 	cam->Position -= glm::normalize(glm::cross(cam->Forward, cameraUp)) * cameraSpeed * deltaTime;
	// if (glfwGetKey(window.m_window, GLFW_KEY_D) == GLFW_PRESS)
	// 	cam->Position += glm::normalize(glm::cross(cam->Forward, cameraUp)) * cameraSpeed * deltaTime;
 // move

	/*
	float lastX, lastY;
	bool firstMouse = true;
	void mouse_callback(GLFWwindow * window, double xpos, double ypos)
		{
			if (firstMouse)
			{
				lastX = xpos;
				lastY = ypos;
				firstMouse = false;
			}

			float xoffset = xpos - lastX;
			float yoffset = lastY - ypos;
			lastX = xpos;
			lastY = ypos;

			float sensitivity = 0.005f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;

			cam->Rotation.x -= xoffset;
			cam->Rotation.y -= yoffset;

			if (cam->Rotation.x > 89.0f)
				cam->Rotation.x = 89.0f;
			if (cam->Rotation.x < -89.0f)
				cam->Rotation.x = -89.0f;
	}
	*/

	/*
		float verticesCube[] = {
			// positions          // normals           // texture coords
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
		};
		*/
