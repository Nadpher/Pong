#include "Engine.h"
#undef main

int main()
{
	try
	{
		Pong::Engine Application({ 1024, 786 });
		Application.Run();
	}
	catch (std::runtime_error& ErrorMessage)
	{
		std::cerr << ErrorMessage.what() << L"\n";
	}

}