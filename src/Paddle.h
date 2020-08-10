#pragma once

#include "Coord.h"

namespace Pong
{
	class Paddle
	{
	public:
		Paddle() = delete;
		Paddle(int pVelocity) : m_Velocity(pVelocity) {}
		~Paddle() = default;

		inline void Move(int pDirection) { m_Position.Y += m_Velocity * pDirection }

	private:
		Coord m_Position = {};
		int m_Velocity;

	public:
		Coord GetPosition() { return m_Position; }
		
	};
}