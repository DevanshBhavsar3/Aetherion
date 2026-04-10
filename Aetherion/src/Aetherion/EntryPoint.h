#pragma once

#ifdef ATH_PLATFORM_WINDOWS

extern Aetherion::Application* Aetherion::CreateApplication();

int main(int argc, int** argv) {
	Aetherion::Log::Init();

	auto app = Aetherion::CreateApplication();
	app->Run();
	delete app;
}

#endif