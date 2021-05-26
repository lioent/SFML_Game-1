#pragma once
#include "Mobile.hpp"
#include "Drawable.hpp"

using namespace Game::Entity::Abstraction;

namespace Game
{
	namespace Entity
	{
		/// <summary>
		/// Class that represents a player in the game.
		/// </summary>
		class Player : public Mobile, public Drawable
		{
		public:
			Player();
			~Player();

			void update() override;
			void move() override;


		private:
			void updateAcceleration();

			bool anyMovementKeyIsPressed() { return upMovementKeyIsPressed() && downMovementKeyIsPressed() && leftMovementKeyIsPressed() && rightMovementKeyIsPressed(); }
			bool upMovementKeyIsPressed();
			bool downMovementKeyIsPressed();
			bool leftMovementKeyIsPressed();
			bool rightMovementKeyIsPressed();

		private:

		};
	}
}