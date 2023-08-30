#pragma once

#ifdef CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv) {

	Coffee::Log::Init();

	auto app = Coffee::CreateApplication();
	app->Run();
	delete app;
	
}

#endif
