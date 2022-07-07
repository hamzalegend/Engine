#pragma once

extern Engine::Application* CreateApplication();

#ifdef HZ_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#endif
