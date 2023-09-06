#include <Coffee.h>

class ExampleLayer : public Coffee::Layer {
public: ExampleLayer()
	:Layer("Example"){}

	void OnUpdate() override {
		auto x = Coffee::Input::IsKeyPressed(CF_KEY_A);
		LOG_CLIENT_TRACE("{0}", x);
	}
};

class Sandbox : public Coffee::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Coffee::ImGuiLayer());
	}

	~Sandbox() {

	}
};


Coffee::Application* Coffee::CreateApplication() {
	return new Sandbox();
}