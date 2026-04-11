#include <Aetherion.h>
#include <iostream>

class ExampleLayer : public Aetherion::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override{
		ATH_INFO("ExampleLayer::Update");
	}

	void OnEvent(Aetherion::Event& e) override {
		ATH_TRACE("{0}", e);
	}
};

class Sandbox: public Aetherion::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	};

	~Sandbox() {};
};

Aetherion::Application* Aetherion::CreateApplication() {
	return new Sandbox();
}