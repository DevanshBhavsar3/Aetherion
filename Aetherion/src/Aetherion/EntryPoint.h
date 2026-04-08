#pragma once

#include <iostream>

#ifdef ATH_PLATFORM_WINDOWS

extern Aetherion::Application* Aetherion::CreateApplication();

int main(int argc, int** argv) {
	Aetherion::Log::Init();
	ATH_CORE_WARN("Hello");
	ATH_INFO("Hello! Var={0}", 5);

	auto app = Aetherion::CreateApplication();
	app->Run();
	delete app;
}

#endif