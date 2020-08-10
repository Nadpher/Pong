#pragma once

#include "Coord.h"

namespace Pong
{
	class Paddle
	{
	public:
		Paddle() = delete;

		Paddle(int pSpeed, Coord pPosition) : m_Speed(pSpeed), m_Position(pPosition) {}
		~Paddle() = default;

		inline void Move(int pDirection) { m_Position.Y += m_Speed * pDirection }

	private:
		Coord m_Position = {};
		int m_Speed;

	public:
		Coord GetPosition() { return m_Position; }
		
	};
}