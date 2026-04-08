#pragma once

#include "Core.h"

namespace Aetherion {

	class AETHERION_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}