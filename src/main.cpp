#include "Engine.h"
#undef main

int main()
{
	try
	{
		Pong::Engine Application({ 1024, 786 });
		
	}
	catch (std::wstring& ErrorMessage)
	{
		std::wcerr << ErrorMessage << L"\n";
	}

}