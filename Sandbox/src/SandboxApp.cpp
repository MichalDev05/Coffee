#include <Coffee.h>

class ExampleLayer : public Coffee::Layer {
public: ExampleLayer()
	:Layer("Example"){}

	/*void OnEvent(Coffee::Event& event) override {
		LOG_CLIENT_TRACE("{0}", event);
	}*/
};

class Sandbox : public Coffee::Application {
public:
	Sandbox() {
		//PushLayer(new ExampleLayer());
		PushOverlay(new Coffee::ImGuiLayer());
	}

	~Sandbox() {

	}
};


Coffee::Application* Coffee::CreateApplication() {
	return new Sandbox();
}