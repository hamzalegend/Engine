#include <Engine.h>
#include <Jaguar/Event/Event.h>
#include <Jaguar/Scene/Scene.h>


class EditorLayer : public Jaguar::Layer
{
private:
	Jaguar::Scene* m_ActiveScene;
public:
	EditorLayer()
	{
		
	}

	void OnUpdate() override
	{
		// JR_CORE_INFO("Update()");
	}
	virtual void OnEvent(Jaguar::Event& event) 
	{
	}
	~EditorLayer()
	{

	}

private:

};

class Sandbox : public Jaguar::Application
{
public:
	Sandbox()
	{
		EditorLayer* editorLayer = new EditorLayer();
		editorLayer->SetEnabled(false);
		PushLayer(editorLayer);
	};
	~Sandbox()
	{

	};
};


Jaguar::Application* Jaguar::CreateApplication()
{
	return new Sandbox();
}