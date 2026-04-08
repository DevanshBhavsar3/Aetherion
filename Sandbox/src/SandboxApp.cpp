#include <Aetherion.h>
#include <iostream>

class Sandbox: public Aetherion::Application {
public:
	Sandbox() {};

	~Sandbox() {};
};

Aetherion::Application* Aetherion::CreateApplication() {
	return new Sandbox();
}