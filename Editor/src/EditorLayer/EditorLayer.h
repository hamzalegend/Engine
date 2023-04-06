#pragma once
#include <Engine.h>



// #include "imgui.h"
// #include "imgui_impl_glfw.h"
// #include "imgui_impl_opengl3.h"
// #include <stdio.h>
// 
// 
// #include <GLFW/glfw3.h> 
// 
// #if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
// #pragma comment(lib, "legacy_stdio_definitions")
// #endif


namespace Jaguar
{
	class EditorLayer : public Layer
	{
	private:

	public:
		Scene* scene = new Scene;
		Entity e = scene->CreateEntity("Square");
		Entity camera = scene->CreateEntity("camera");

		EditorLayer();

		virtual void OnAttach() override;
	
		virtual void OnUpdate(float deltaTime) override;
		
		virtual void OnEvent(Jaguar::Event& event) override;

		~EditorLayer();

	private:

	};
}



