#pragma once
#include "Static.hpp"
#include "Drawable.hpp"

using namespace Game::Entity::Abstraction;

namespace Game
{
	namespace Entity
	{
		/// <summary>
		/// Represents a collidable platform that Solid entities are going to be able to interact on.
		/// </summary>
		class Platform : public Static, Drawable
		{
		public:
			Platform();
			~Platform();

		private:
		};
	}
}
