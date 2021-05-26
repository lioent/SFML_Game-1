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

			void position(sf::Vector2f position);
			void size(sf::Vector2f size);

			// temporary solution for the lack of textures -> should become the intRect in the future
			sf::RectangleShape* body() const { return _rigidBody; }

		private:
			// temporary solution for the lack of textures -> should become the intRect in the future
			sf::RectangleShape* _rigidBody;

		};
	}
}
