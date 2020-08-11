#include "GameBoard.h"

#include <iostream>

void Pong::GameBoard::Update()
{
	m_Ball.Move();
	BallPositionCheck();
	PaddleOOB();
	PaddleCollisions();	
}

void Pong::GameBoard::BallPositionCheck()
{
	Coord BallPosition = m_Ball.GetPosition();
	int BallRadius = m_Ball.GetRadius();

	if (BallPosition.Y + m_Ball.GetRadius() > m_PlayAreaBounds.Y)
	{
		m_Ball.FlipVertical();
	}
	else if (BallPosition.Y < 0)
	{
		m_Ball.FlipVertical();
	}

	// Position offset to fix bug causing the ball to score before colliding with paddles
	// The couts are temporary until i include sdl_ttf and draw the score directly on the renderer
	constexpr int POSITION_OFFSET = 10;
	if (BallPosition.X + BallRadius > m_Paddles[Right].GetPosition().X + POSITION_OFFSET)
	{
		m_Paddles[Left].IncreaseScore();
		std::cout << "Left player score: " << m_Paddles[Left].GetScore() << "\n";

		m_Ball.Reset();
	}
	else if (BallPosition.X < m_Paddles[Left].GetPosition().X + m_Paddles[Left].GetSize().X - POSITION_OFFSET)
	{
		m_Paddles[Right].IncreaseScore();
		std::cout << "Right player score: " << m_Paddles[Right].GetScore() << "\n";

		m_Ball.Reset();
	}
}

void Pong::GameBoard::PaddleCollisions()
{
	Coord BallPosition = m_Ball.GetPosition();
	int BallRadius = m_Ball.GetRadius();

	for (int i = 0, size = m_Paddles.size(); i < size; ++i)
	{
		if (AABBCollision(
			m_Paddles[i].GetPosition(), m_Paddles[i].GetSize(),
			BallPosition, { BallRadius, BallRadius }))
		{
			m_Ball.FlipHorizontal();
		}
	}
}

void Pong::GameBoard::PaddleOOB()
{
	for (int i = 0, size = m_Paddles.size(); i < size; ++i)
	{
		int PaddleYPosition = m_Paddles[i].GetPosition().Y;
		int PaddleHeight = m_Paddles[i].GetSize().Y;

		if (PaddleYPosition < 0)
		{
			m_Paddles[i].ResetOOB(PaddleYPosition * -1);
		}
		else if (PaddleYPosition + PaddleHeight > m_PlayAreaBounds.Y)
		{
			m_Paddles[i].ResetOOB(m_PlayAreaBounds.Y - (PaddleYPosition + PaddleHeight));
		}
	}
}

bool Pong::GameBoard::AABBCollision(Coord Position1, Coord Size1, Coord Position2, Coord Size2)
{
	return Position1.X < Position2.X + Size2.X &&
		Position1.X + Size1.X > Position2.X &&
		Position1.Y < Position2.Y + Size2.Y &&
		Position1.Y + Size1.Y > Position2.Y;
}