#pragma once
#include "Mobile.hpp"
#include "Solid.hpp"

#include <map>

using namespace Game::Entity::Abstraction;

namespace Game
{
	namespace Manager
	{
		/// <summary>
		/// Manager that controls the physical interactions between the entities of the system
		/// </summary>
		class PhysicManager
		{
		public:
			PhysicManager();
			~PhysicManager();

			void update(Mobile& entity, float deltaTime);
			void updateCollision(Mobile& entity, Mobile& collider, float deltaTime);
			void updateCollision(Mobile& entity, Solid& collider, float deltaTime);

		private:
			void applyGravity(Mobile& entity, float deltaTime);
			void applyDeceleration(Mobile& entity);
			sf::Vector2<bool> checkCollision(Solid& entity, Solid& collider);


		private:
			static const float GRAVITY;
			static const float DECELERATION_RATE;

		};
	}
}
