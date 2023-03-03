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

	Entity Scene::CreateEntity(std::string name)
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

		// auto group = m_Registry.group<TransformComponent>(entt::get<MeshRendererComponent>);
		// for (auto entity : group)
		// {
		// 	auto& [transform, MRC] = group.get<TransformComponent, MeshRendererComponent>(entity);
		// 	std::cout << MRC.mesh.color.x << " , " << MRC.mesh.color.y << " , " << MRC.mesh.color.z << std::endl;
		// }

		// Renderer::BeginScene(cam); // TODO :: yes;
		{
			auto group = m_Registry.group<TransformComponent>(entt::get<MeshRendererComponent>);
			for (auto entity : group)
			{
				//auto& [transform, Mesh] = group.get<TransformComponent, MeshRendererComponent>(entity);
				TransformComponent transform = group.get<TransformComponent>(entity);
				MeshRendererComponent mesh= group.get<MeshRendererComponent>(entity);

				Renderer::Submit(mesh.mesh, transform.Transform); // TODO :: fix

				// std::cout << transform.Transform[0][0] << " , " << transform.Transform[3][1] << " , " << transform.Transform[3][2] << std::endl;
				// Renderer2D::DrawSprite(transform.GetTransform(), sprite, (int)entity);
			}
		}

		// Render
		{
			// Renderer::BeginScene(cam);
			// Renderer::Submit(va, shader, Transform);
			// Renderer::Flush();
			// Renderer::EndScene();		
		}
	}

}