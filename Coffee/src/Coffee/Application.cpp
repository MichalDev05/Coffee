#include "Application.h"

#include "Coffee/Events/ApplicationEvent.h"
#include "Coffee/Log.h"

namespace Coffee {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryInput)) {

			LOG_CLIENT_INFO(e);
		}
		
		while (true);
	}


}

