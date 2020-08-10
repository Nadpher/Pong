#include "Engine.h"

// This is really bad.
Pong::Engine::Engine(Coord pWindowSize)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		throw std::runtime_error("Could not initialize SDL");
	}

	InitWindow(pWindowSize, "Pong!");
	InitRenderer();
}

// TODO: CLEANUP CONSTRUCTORS and fix stuff
Pong::Engine::Engine(Coord pWindowSize, const char* pWindowTitle)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		throw std::runtime_error("Could not initialize SDL");
	}

	InitWindow(pWindowSize, pWindowTitle);
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

void Pong::Engine::InitWindow(Coord pWindowSize, const char* pWindowTitle)
{
	m_Window = SDL_CreateWindow(
		pWindowTitle,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		pWindowSize.X,
		pWindowSize.Y,
		SDL_WINDOW_SHOWN
	);

	if (m_Window == nullptr)
	{
		throw std::runtime_error("Could not initialize SDL window");
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
		throw std::runtime_error("Could not initialize SDL renderer");
	}
}