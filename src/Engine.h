#pragma once

#include "GameBoard.h"

#include <SDL.h>

namespace Pong
{
	class Engine
	{
	public:
		Engine() = delete;
		Engine(Coord pWindowSize);
		Engine(Coord pWindowSize, const char* pWindowTitle);

		~Engine() = default;

		void Run();

	private:

		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;

		GameBoard m_GameBoard;
		
		bool m_Running = true;
		void InitWindow(Coord pWindowSize, const char* pWindowTitle);
		void InitRenderer();
		
		void HandleEvents();
		void Quit();

		void Draw();
		void DrawBall();
	};
}