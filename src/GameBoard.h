#pragma once

#include "Ball.h"

namespace Pong
{
	class GameBoard
	{
	public:
		GameBoard() = delete;
		GameBoard(Coord pWindowSize) 
			: m_PlayAreaBounds(pWindowSize),
			m_Ball({ 20, 20 }, { m_PlayAreaBounds.X / 2, m_PlayAreaBounds.Y / 2 })
		{

		}

		~GameBoard() = default;

		void Update();

		inline Coord GetPlayAreaBounds() { return m_PlayAreaBounds;				}
		inline Coord GetBallPosition()   { return m_Ball.GetPosition();			}
		inline int GetBallRadius()       { return m_Ball.GetRadius();			}

		enum Direction
		{
			Up = -1,
			Down = 1
		};

	private:
		const Coord m_PlayAreaBounds;
		
		Ball m_Ball;
	};
}