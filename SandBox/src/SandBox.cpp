#include <Engine.h>

class ExapleLayer : public Jaguar::Layer
{
public:
	ExapleLayer()
	{

	}

	void OnUpdate()
	{
		JR_CORE_INFO("Update()");
	}

	~ExapleLayer()
	{

	}

private:

};

class Sandbox : public Jaguar::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExapleLayer());
	};
	~Sandbox()
	{

	};
};


Jaguar::Application* Jaguar::CreateApplication()
{
	return new Sandbox();
}