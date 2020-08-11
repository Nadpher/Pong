#pragma once

#include "Ball.h"
#include "Paddle.h"
#include <vector>

namespace Pong
{
	class GameBoard
	{
	public:
		GameBoard() = delete;
		
		// This could be improved
		GameBoard(Coord pWindowSize)
			: m_PlayAreaBounds(pWindowSize),
			m_Ball({ 10, m_PlayAreaBounds.X / 30 }, { m_PlayAreaBounds.X / 2, m_PlayAreaBounds.Y / 2 }),
			m_Paddles{ 
						{  // Left paddle
							{m_PlayAreaBounds.X / 30, m_PlayAreaBounds.Y / 3}, // Size Left
							{0, m_PlayAreaBounds.Y / 3},					   // Position
							20												   // Speed						
						}, 
						   // Right paddle
						{
							{m_PlayAreaBounds.X / 30, m_PlayAreaBounds.Y / 3},					    // Size
							{m_PlayAreaBounds.X - m_PlayAreaBounds.X / 30, m_PlayAreaBounds.Y / 3}, // Position
							20																		// Speed
						}
					 }
		{
			
		}


		~GameBoard() = default;

		void Update();

		inline Coord GetPlayAreaBounds() { return m_PlayAreaBounds;				}
		inline Coord GetBallPosition()   { return m_Ball.GetPosition();			}
		inline int GetBallRadius()       { return m_Ball.GetRadius();			}

		inline void MoveLeftPaddle(int pDirection)  { m_Paddles[Left].Move(pDirection); }
		inline void MoveRightPaddle(int pDirection) { m_Paddles[Right].Move(pDirection); }

		inline Coord GetLeftPaddleSize()      { return m_Paddles[Left].GetSize();     }
		inline Coord GetRightPaddleSize()     { return m_Paddles[Right].GetSize();     }
		inline Coord GetLeftPaddlePosition()  { return m_Paddles[Left].GetPosition(); }
		inline Coord GetRightPaddlePosition() { return m_Paddles[Right].GetPosition(); }

		enum Direction
		{
			Up = -1,
			Down = 1
		};

	private:
		const Coord m_PlayAreaBounds;
		std::vector<Paddle> m_Paddles = {};

		Ball m_Ball;

		void BallPositionCheck();
		void PaddleCollisions();
		void PaddleOOB();
		void Score(int pIndex);
		bool AABBCollision(Coord Position1, Coord Size1, Coord Position2, Coord Size2);		

		// For readability
		enum Paddles
		{
			Left = 0,
			Right
		};
	};
}