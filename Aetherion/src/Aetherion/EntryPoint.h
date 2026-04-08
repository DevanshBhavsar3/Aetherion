#pragma once

#include <iostream>

#ifdef ATH_PLATFORM_WINDOWS

extern Aetherion::Application* Aetherion::CreateApplication();

int main(int argc, int** argv) {
	std::cout << "Aetherion Enginer\n";
	auto app = Aetherion::CreateApplication();
	app->Run();
	delete app;
}

#endif