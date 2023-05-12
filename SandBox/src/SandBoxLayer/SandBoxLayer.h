#pragma once

#include <Engine.h>

namespace Jaguar
{
	class SandBoxLayer : public Layer
	{
	private:

	public:
		Scene* scene = new Scene;
		Entity e = scene->CreateEntity("Square");
		Entity camera = scene->CreateEntity("camera");

		SandBoxLayer() {};
		~SandBoxLayer();
		
		virtual void OnAttach() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnEvent(Jaguar::Event& event) override;

	

	};
}

