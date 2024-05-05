#include "Saber.h"

class SandBox :public Saber::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

Saber::Application* Saber::CreateApplication()
{
	return new SandBox();
}