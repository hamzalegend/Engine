#include "Engine.h"

#include <Jaguar/EntryPoint.h>

namespace Jaguar
{
	std::vector<float> Verticess = {
		// positions          // colors                // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	std::vector<unsigned int> indicess = {
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
			{
				e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
				e.AddComponent<MeshRendererComponent>();
				e.GetComponent<MeshRendererComponent>().mesh.Vertices = Verticess;
				e.GetComponent<MeshRendererComponent>().mesh.indices = indicess;
				e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);


				camera.AddComponent<CameraComponent>();
				camera.GetComponent<CameraComponent>().cam = new Camera();
				Camera* cam = camera.GetComponent<CameraComponent>().cam;
				cam->Transform = &camera.GetComponent<TransformComponent>();
				cam->Transform->Position.z = -4;
			}
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

class EditorApplication : public Jaguar::Application
{
public:
	EditorApplication()
	{
		Jaguar::SandBoxLayer* sandBoxLayer = new Jaguar::SandBoxLayer();
		sandBoxLayer->SetEnabled(true);
		PushLayer(sandBoxLayer);
	};
	~EditorApplication()
	{

	};
};


Jaguar::Application* Jaguar::CreateApplication()
{
	return new EditorApplication();
}
