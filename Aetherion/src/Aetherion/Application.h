#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Aetherion {

	class AETHERION_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Called by clients
	Application* CreateApplication();
}