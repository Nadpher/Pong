#pragma once

#include "Coord.h"

namespace Pong
{
	class Ball
	{
	public:
		Ball() = delete;
		Ball(Coord pSpeedAndRadius, Coord pPosition)
			: m_InitialPosition(pPosition),
			m_Position(pPosition),
			m_Speed(pSpeedAndRadius.X),
			m_Radius(pSpeedAndRadius.Y)
		{

		}

		Ball(Coord pSpeedAndRadius, Coord pPosition, Coord pStartingDirection)
			: m_InitialPosition(pPosition),
			m_Position(pPosition),
			m_Speed(pSpeedAndRadius.X),
			m_Radius(pSpeedAndRadius.Y),
			m_DirectionNormals(pStartingDirection),
			m_InitialDirection(pStartingDirection)
		{

		}

		~Ball() = default;

		inline int GetRadius()           { return m_Radius;                }
		inline Coord GetPosition()		 { return m_Position;              }

		inline void FlipVertical()		 { m_DirectionNormals.Y *= -1;     }
		inline void FlipHorizontal()	 { m_DirectionNormals.X *= -1;     }

		inline void Reset()
		{ 
			m_DirectionNormals = m_InitialDirection;
			m_Position = m_InitialPosition;			
		}

		inline void Move()
		{
			m_Position.X += m_Speed * m_DirectionNormals.X;
			m_Position.Y += m_Speed * m_DirectionNormals.Y;
		}

	private:
		const Coord m_InitialPosition;
		const Coord m_InitialDirection = { 1, 1 };
		const int m_Speed;
		const int m_Radius;

		Coord m_DirectionNormals = { 1, 1 };
		Coord m_Position;
	};
}