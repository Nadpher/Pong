#pragma once

#include "Paddle.h"
#include "Ball.h"

#include <array>

namespace Pong
{
	class Board
	{
	public:
		Board() = delete;

		// I made the constructor so that most variables
		// could be modified directly from the Engine class
		Board(
			Coord PaddleSpeeds,
			Coord LeftPaddlePosition,
			Coord RightPaddlePosition,
			Coord BallPosition,
			Coord BallSpeedAndRadius
		)
			: m_Paddles({PaddleSpeeds.X, LeftPaddlePosition}, {PaddleSpeeds.Y, RightPaddlePosition}),
			  m_Ball({BallSpeedAndRadius, BallPosition}) {}

		void Update();

	private:

		std::array<Paddle, 2> m_Paddles;
		Ball m_Ball;

		bool CollisionDetection();
	};
}