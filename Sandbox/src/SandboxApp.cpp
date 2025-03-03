#include <GlowEngine.h>

class Sandbox : public Glow::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Glow::Application* Glow::CreateApplication()
{
	return new Sandbox();
}