#pragma once

#ifdef JR_PLATFORM_WINDOWS

extern Jaguar::Application* CreateApplication();

int main(int argc, char** argv)
{
	Jaguar::Log::Init();

	JR_CORE_INFO("INITIALIZING ENGINE..");
	JR_CORE_TRACE("\n\nWolcome to Jaguar!\n\n");

	auto app = Jaguar::CreateApplication();
	app->Run();
	delete app;
}
#endif
