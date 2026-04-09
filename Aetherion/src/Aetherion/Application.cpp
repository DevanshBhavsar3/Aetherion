#include "Application.h"

#include "Aetherion/Events/ApplicationEvent.h"
#include "Aetherion/Log.h"

namespace Aetherion {

	Application::Application() {};
	Application::~Application() {};

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		ATH_TRACE(e);

		while (true) {};
	}
}