#pragma once
#include "Coord.h"

namespace Pong
{
	class Ball
	{
	public:
		Ball() = delete;

		Ball(Coord SpeedAndRadius, Coord pPosition) : m_Speed(SpeedAndRadius.X), m_Radius(SpeedAndRadius.Y) {}
		~Ball() = default;
		
		Coord GetPosition() { return m_Position; }

		inline void FlipVertical() { DirectionNormals.Y *= -1 }
		inline void FlipHorizontal() { DirectionNormals.X *= -1; }

		inline void Move()
		{
			m_Position.X += m_Speed * DirectionNormals.X;
			m_Position.Y += m_Speed * DirectionNormals.Y;
		}

	private:

		int m_Speed;
		int m_Radius;
		Coord m_Position = {};
		Coord DirectionNormals = {1, 1};
	};
}