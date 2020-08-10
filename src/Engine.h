#pragma once

#include "Coord.h"

#include <SDL.h>
#include <iostream>

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
		const Coord m_WindowSize = { };
		bool m_Running = true;
		
		void InitWindow(const char* pWindowTitle);
		void InitRenderer();
		void Draw();
		void HandleEvents();
		void Quit();

		enum Paddles
		{
			Left = 0,
			Right
		};

		enum Direction
		{
			Up = -1,
			Down = 1
		};

	public:
		Coord GetWindowSize() { return m_WindowSize; }
	};
}