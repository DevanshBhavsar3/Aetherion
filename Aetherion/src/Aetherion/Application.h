#pragma once

#include "Aetherion/Events/Event.h"
#include "Aetherion/Events/ApplicationEvent.h"
#include "Aetherion/Window.h"
#include "Aetherion/LayerStack.h"

namespace Aetherion {

	class AETHERION_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// Called by clients
	Application* CreateApplication();
}