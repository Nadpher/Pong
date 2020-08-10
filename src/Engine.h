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
		
		bool m_Running = true;
		void InitWindow(Coord pWindowSize, const char* pWindowTitle);
		void InitRenderer();
		void Draw();
		void HandleEvents();
		void Quit();
	};
}