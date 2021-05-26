#pragma once
#include "Mobile.hpp"

using namespace Game::Entity::Abstraction;

namespace Game
{
	namespace Manager
	{
		/// <summary>
		/// Manages and updates every entity in the game
		/// </summary>
		class EntityManager
		{
		public:
			EntityManager();
			~EntityManager();

			void update(Mobile& entity, float deltaTime);

		private:
		};
	}
}
