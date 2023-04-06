
#include <Engine.h>
#include "Jaguar/EntryPoint.h"

#include "EditorLayer/EditorLayer.h"

class EditorApplication : public Jaguar::Application
{
public:
	EditorApplication()
	{
		Jaguar::EditorLayer* editorLayer = new Jaguar::EditorLayer();
		editorLayer->SetEnabled(true);
		PushLayer(editorLayer);
	};

	~EditorApplication()
	{
	};
};


Jaguar::Application* Jaguar::CreateApplication()
{
	return new EditorApplication();
}
