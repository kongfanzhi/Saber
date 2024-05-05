#pragma once

#ifdef SABER_PLATFORM_WINDOWS

extern Saber::Application* Saber::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Saber::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error saber only support windows
#endif