#pragma once

#include "Core.h"
#include "Window.h"
#include "Coffee/LayerStack.h"
#include "Coffee/Events/Event.h"
#include "Coffee/Events/ApplicationEvent.h"


namespace Coffee {

	class COFFEE_API Application
	{
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

	Application* CreateApplication();
}


