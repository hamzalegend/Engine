#include <Engine.h>

class Sandbox : public Jaguar::Application
{
public:
	Sandbox()
	{
		
	};
	~Sandbox()
	{

	};
};
Jaguar::Application* Jaguar::CreateApplication()
{
	return new Sandbox();
}