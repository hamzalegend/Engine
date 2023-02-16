#include "Scene.h"
#include "Jaguar/Math.h"
namespace Jaguar
{

	struct TranformComponent
	{
		Mat4 Transform;
		TranformComponent() = default;
		TranformComponent(Mat4 transform) 
			:Transform(transform)
		{};
		operator glm::mat4& () { return Transform; }
	};


	Scene::Scene()
	{
		// entt::entity e1 = m_Registry.create();
		// 
		// m_Registry.emplace<TranformComponent>(e1);
	}

	Scene::~Scene()
	{

	}

	void Scene::OnUpdate(float deltaTime)
	{
	}

}