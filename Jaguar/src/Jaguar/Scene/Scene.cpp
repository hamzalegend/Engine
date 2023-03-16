#include "Scene.h"

#include "Components.h"
#include "Entity.h"

#include "Jaguar/Math.h"
#include "Jaguar/Log/log.h"

#include "Jaguar/Renderer/Renderer.h"

#include <iostream>


namespace Jaguar
{

	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity e = { m_Registry.create(), this };
		e.AddComponent<TagComponent>(name);
		e.AddComponent<TransformComponent>();
		return e;
	}

	void Scene::OnUpdate(float deltaTime)
	{
		// auto group = m_Registry.group<TransformComponent>(entt::get<TagComponent>);
		// for (auto entity : group)
		// {
		// 	auto& [transform, tag] = group.get<TransformComponent, TagComponent>(entity);
		// 	// std::cout <<  tag.name << " , " << std::endl;
		// }

		// Primary Camera:
		CameraComponent* PrimaryCam;
		{
			auto view = m_Registry.view<CameraComponent>();
			for (auto entity : view)
			{
				CameraComponent& cam = view.get<CameraComponent>(entity);
				if (cam.Primary)
					PrimaryCam = &cam;
				// std::cout << MRC.mesh.color.x << " , " << MRC.mesh.color.y << " , " << MRC.mesh.color.z << std::endl;
			}
		}

		// Render:
		{
			Renderer::BeginScene(PrimaryCam->cam);
			auto group = m_Registry.group<TransformComponent>(entt::get<MeshRendererComponent>);
			for (auto entity : group)
			{
				TransformComponent& transform = group.get<TransformComponent>(entity);
				MeshRendererComponent& mesh= group.get<MeshRendererComponent>(entity);

				Renderer::Submit(mesh.mesh, transform.Transform);
			}
			Renderer::Flush();
			Renderer::EndScene();	
		}

	}

}