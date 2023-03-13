#pragma once

#include "Scene.h"
#include "Entt/entt.h"
#include "Jaguar/Log/log.h"

namespace Jaguar
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity EntityHandle, Scene* Scene)
			:m_EntityHandle(EntityHandle), m_Scene(Scene)
		{
		}
		~Entity() {};

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			JR_CORE_ASSERT(HasComponent<T>(), "Alraedy has Component!");
			if (!HasComponent<T>())
				return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
			else
				return GetComponent<T>();
		}

		template<typename T>
		T& GetComponent()
		{
			JR_CORE_ASSERT(!HasComponent<T>(), "Doesnt Have Component!");
			if (HasComponent<T>())
				return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponent()
		{
			// return m_Scene->m_Registry.has // doesnt Work
			return m_Scene->m_Registry.any_of<T>(m_EntityHandle);
		}

		template<typename T>
		bool RemoveComponent()
		{
			JR_CORE_ASSERT(!HasComponent<T>(), "Doesnt Have Component!");
			return m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}
		
		
	private:
		entt::entity m_EntityHandle;
		Scene* m_Scene;
	};

};