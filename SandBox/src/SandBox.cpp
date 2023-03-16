// #include <Engine.h>
#include <Jaguar/Event/Event.h>
#include <Jaguar/Scene/Scene.h>
#include <Jaguar/Scene/Components.h>



#include "Jaguar/Log/log.h"

#include "Jaguar/Renderer/Renderer.h"
#include "Jaguar/Camera/Camera.h"
#include "Jaguar/Input/Input.h"

#include <Jaguar/Scene/Scene.h>
#include <Jaguar/Scene/Components.h>
#include <Jaguar/Scene/Entity.h>

#pragma once
// for use by client

#include "Jaguar/Application.h"

#include "Jaguar/Log/log.h"

#include "Jaguar/EntryPoint.h"

// #include "Jaguar/Window/Window.h"

#include "API/OpenGL/ShaderGL.h"
#include "Jaguar/Scene/Scene.h"

// #include <Engine.h>
#include <Jaguar/Event/Event.h>
#include <Jaguar/Scene/Scene.h>
#include <Jaguar/Scene/Components.h>



#include "Jaguar/Log/log.h"

#include "Jaguar/Renderer/Renderer.h"
#include "Jaguar/Camera/Camera.h"
#include "Jaguar/Input/Input.h"

#include <Jaguar/Scene/Scene.h>
#include <Jaguar/Scene/Components.h>
#include <Jaguar/Scene/Entity.h>

namespace Jaguar
{

	/*
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
	*/

	class SandBoxLayer : public Layer
	{
	private:
		
		Entity e;
		// Entity camera;
	public:
		SandBoxLayer()
		{
		}

		void OnAttach() override
		{
			// e = scene->CreateEntity("as");
			// JR_CORE_INFO("start()");
			// scene = new Scene;
			// e = scene->CreateEntity("Square");
			// camera = scene->CreateEntity("camera");
			// 
			// e.GetComponent<TransformComponent>().Transform = Mat4(1.0f);
			// e.AddComponent<MeshRendererComponent>();
			// e.GetComponent<MeshRendererComponent>().mesh.Vertices = Vertices;
			// e.GetComponent<MeshRendererComponent>().mesh.indices = indices;
			// e.GetComponent<MeshRendererComponent>().mesh.color = Vector4(25, 52, 63, 0);
			// 
			// 
			// 
			// camera.AddComponent<CameraComponent>();
			// camera.GetComponent<CameraComponent>().cam = new Camera();
			// Camera* cam = camera.GetComponent<CameraComponent>().cam;
			// cam->Transform = &camera.GetComponent<TransformComponent>();

		};

		void OnUpdate() override
		{
			// JR_CORE_INFO("Update()");
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