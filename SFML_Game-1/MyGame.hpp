#pragma once
#include "Game.hpp"

namespace Game
{
	// Represents the game itself.
	class MyGame : public Game
	{
	public:
		MyGame(string name = "My game");
		~MyGame();

		void run() override;
		void exit() override;

	private:
	};
}