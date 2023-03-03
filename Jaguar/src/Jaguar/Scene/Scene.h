#pragma once

#include "Entt/entt.h"
#include "Jaguar/Core.h"
#include <Jaguar/Camera/Camera.h>

namespace Jaguar
{
	class Entity;
	class JAGUAR_API Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(std::string name = "New Entity");

		void OnUpdate(float deltaTime);

	private:
		entt::registry m_Registry;

		friend Entity;
	};

}