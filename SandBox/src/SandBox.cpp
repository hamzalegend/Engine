#include "Engine.h"



#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>


#include <GLFW/glfw3.h> 

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

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
			{
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
			}
		};
		


			// IMGUI_CHECKVERSION();
			// ImGui::CreateContext();
			// ImGuiIO& io = ImGui::GetIO(); (void)io;
			// io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
			// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
			// io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
			// io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
			// ImGui::StyleColorsDark();
			// ImGuiStyle& style = ImGui::GetStyle();
			// if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			// {
			// 	style.WindowRounding = 0.0f;
			// 	style.Colors[ImGuiCol_WindowBg].w = 1.0f;
			// }
			// 
			// ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)Application::Get().GetWindow()->GetNative(), true);
			// ImGui_ImplOpenGL3_Init("#version 130");
		
		
		// bool show_demo_window = true;
		// bool show_another_window = false;
		// ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

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
			{
				// Start the Dear ImGui frame
				// ImGui_ImplOpenGL3_NewFrame();
				// ImGui_ImplGlfw_NewFrame();
				// ImGui::NewFrame();

				// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
				// if (show_demo_window)
				// 	ImGui::ShowDemoWindow(&show_demo_window);
			}

			/* {
				// Rendering
				ImGui::Render();
				int display_w, display_h;
				glfwGetFramebufferSize(window, &display_w, &display_h);
				glViewport(0, 0, display_w, display_h);
				glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
				glClear(GL_COLOR_BUFFER_BIT);
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

				// Update and Render additional Platform Windows
				// (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
				//  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
				if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
				{
					GLFWwindow* backup_current_context = glfwGetCurrentContext();
					ImGui::UpdatePlatformWindows();
					ImGui::RenderPlatformWindowsDefault();
					glfwMakeContextCurrent(backup_current_context);
				}*/
			
			scene->OnUpdate(deltaTime);
		}

		virtual void OnEvent(Jaguar::Event& event)
		{
		}

		~SandBoxLayer()
		{
			// Cleanup
			// ImGui_ImplOpenGL3_Shutdown();
			// ImGui_ImplGlfw_Shutdown();
			// ImGui::DestroyContext();
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
