#pragma once

#include "Aetherion/Core.h"
#include "Aetherion/Events/Event.h"
#include "Aetherion/Window.h"

namespace Aetherion {

	class AETHERION_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Called by clients
	Application* CreateApplication();
}