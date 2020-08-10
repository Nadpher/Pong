#pragma once

#include "Paddle.h"

#include <array>

namespace Pong
{
	class Board
	{
	public:
		Board(Coord PaddleVelocities, Coord BallVariables)

		void Update();

	private:

		std::array<Paddle, 2> m_Paddles;
		// Ball m_Ball;
	};
}