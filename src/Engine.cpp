#include "Engine.h"

Pong::Engine::Engine(Coord pWindowSize)
	: m_WindowSize(pWindowSize)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		throw std::wstring(L"Could not initialize SDL");
	}

	InitWindow("Pong!");
	InitRenderer();
}

Pong::Engine::Engine(Coord pWindowSize, const char* pWindowTitle)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		throw std::wstring(L"Could not initialize SDL");
	}

	InitWindow(pWindowTitle);
	InitRenderer();
}

void Pong::Engine::Run()
{
	// Sets render draw color to black
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);

	while (m_Running)
	{
		HandleEvents();

		Draw();
	}
}

void Pong::Engine::Draw()
{
	SDL_RenderClear(m_Renderer);

	SDL_RenderPresent(m_Renderer);
}

void Pong::Engine::HandleEvents()
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			m_Running = false;
			break;
		}
	}
}

void Pong::Engine::Quit()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);

	SDL_Quit();
}

void Pong::Engine::InitWindow(const char* pWindowTitle)
{
	m_Window = SDL_CreateWindow(
		pWindowTitle,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		m_WindowSize.X,
		m_WindowSize.Y,
		SDL_WINDOW_SHOWN
	);

	if (m_Window == nullptr)
	{
		throw std::wstring(L"Could not initialize SDL window");
	}
}

void Pong::Engine::InitRenderer()
{
	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED
	);

	if (m_Renderer == nullptr)
	{
		throw std::wstring(L"Could not initialize SDL renderer");
	}
}