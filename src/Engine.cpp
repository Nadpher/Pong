#include "Engine.h"

#include <stdexcept>

Pong::Engine::Engine(Coord pWindowSize)
	: m_GameBoard(pWindowSize), m_Keys(SDL_GetKeyboardState(NULL))
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		throw std::runtime_error("Could not initialize SDL");
	}

	InitWindow(pWindowSize, "Pong!");
	InitRenderer();
}

Pong::Engine::Engine(Coord pWindowSize, const char* pWindowTitle)
	: m_GameBoard(pWindowSize), m_Keys(SDL_GetKeyboardState(NULL))
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
		m_GameBoard.Update();
		Draw();
	}
}

void Pong::Engine::Draw()
{
	SDL_RenderClear(m_Renderer);

	DrawBall();
	DrawPaddles();

	SDL_RenderPresent(m_Renderer);
}

void Pong::Engine::DrawBall()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
	Coord BallPosition = m_GameBoard.GetBallPosition();
	int BallRadius = m_GameBoard.GetBallRadius();

	SDL_Rect Ball; // I know it should be a circle but i cant be bothered to implement the midpoint algorithm (or include sdl gfx)
	Ball.x = BallPosition.X;
	Ball.y = BallPosition.Y;
	Ball.w = BallRadius;
	Ball.h = BallRadius;

	SDL_RenderFillRect(m_Renderer, &Ball);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}

void Pong::Engine::DrawPaddles()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	SDL_Rect Paddle;
	{
		Coord LeftPaddleSize = m_GameBoard.GetLeftPaddleSize();
		Coord LeftPaddlePosition = m_GameBoard.GetLeftPaddlePosition();

		Paddle.x = LeftPaddlePosition.X;
		Paddle.y = LeftPaddlePosition.Y;
		Paddle.w = LeftPaddleSize.X;
		Paddle.h = LeftPaddleSize.Y;
		SDL_RenderFillRect(m_Renderer, &Paddle);
	}

	{
		Coord RightPaddleSize = m_GameBoard.GetRightPaddleSize();
		Coord RightPaddlePosition = m_GameBoard.GetRightPaddlePosition();

		Paddle.x = RightPaddlePosition.X;
		Paddle.y = RightPaddlePosition.Y;
		Paddle.w = RightPaddleSize.X;
		Paddle.h = RightPaddleSize.Y;
		SDL_RenderFillRect(m_Renderer, &Paddle);
	}

	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
}

void Pong::Engine::HandleEvents()
{
	SDL_Event Event;
	SDL_PumpEvents();

	if (m_Keys[SDL_SCANCODE_W])
	{
		m_GameBoard.MoveLeftPaddle(GameBoard::Up);
	}
	if (m_Keys[SDL_SCANCODE_S])
	{
		m_GameBoard.MoveLeftPaddle(GameBoard::Down);
	}

	if (m_Keys[SDL_SCANCODE_UP])
	{
		m_GameBoard.MoveRightPaddle(GameBoard::Up);
	}
	if (m_Keys[SDL_SCANCODE_DOWN])
	{
		m_GameBoard.MoveRightPaddle(GameBoard::Down);
	}

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
	delete m_Keys;

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