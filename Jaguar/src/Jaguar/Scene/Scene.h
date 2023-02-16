#pragma once

#include "Entt/entt.h"
#include "Jaguar/Core.h"
#include <Jaguar/Camera/Camera.h>

namespace Jaguar
{
	class JAGUAR_API Scene
	{
	public:
		Scene();
		~Scene();

		void OnUpdate(float deltaTime);

		Camera* SceneCamera;

	private:

		// entt::registry m_Registry;

	};

}