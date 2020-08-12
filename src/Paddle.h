#pragma once

#include "Coord.h"

namespace Pong
{
	class Paddle
	{
	public:
		Paddle() = delete;

		Paddle(Coord pSize, Coord pPosition, int pSpeed)
			: m_Size(pSize),
			m_Position(pPosition),
			m_Speed(pSpeed)
		{

		}

		~Paddle() = default;

		inline Coord GetSize()			 { return m_Size;						 }
		inline Coord GetPosition()		 { return m_Position;					 }
		inline int GetScore()			 { return m_Score;						 }

		inline void Move(int pDirection) { m_Position.Y += m_Speed * pDirection; }
		inline void IncreaseScore()		 { m_Score++; }

		inline void ResetOOB(int pDifference) { m_Position.Y += pDifference; }

	private:
		const Coord m_Size;
		const int m_Speed;
		Coord m_Position;
		int m_Score = 0;
	};
}