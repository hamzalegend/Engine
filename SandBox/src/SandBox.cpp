#include <Engine.h>
#include <Jaguar/Event/Event.h>


class EditorLayer : public Jaguar::Layer
{
public:
	EditorLayer()
	{
		Jaguar::Scene* mainScene = new Jaguar::Scene;
	}

	void OnUpdate() override
	{
		// JR_CORE_INFO("Update()");
	}
	virtual void OnEvent(Jaguar::Event& event) 
	{
		// const char* name = event.GetName().c_str();
		JR_CORE_ERROR("Event :  !!");
		// JR_CORE_TRACE("{0}", (int)event.catigory);
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