#pragma once
#include "Mobile.hpp"
#include "Solid.hpp"

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

			bool checkCollision(Solid& entity, Solid& collider, float pushBack);

		private:
			void applyGravity(Mobile& entity, float deltaTime);
			void applyDeceleration(Mobile& entity, float deltaTime);


		private:
			static const float GRAVITY;
			static const float DECELERATION_RATE;
		};
	}
}
