#include <GEWS.h>

class Sandbox : public GEWS::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

GEWS::Application* GEWS::CreateApplication()
{
	return new Sandbox();
}