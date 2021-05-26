#pragma once
#include "BaseEntity.hpp"
#include <SFML/Graphics.hpp>

namespace Game
{
	namespace Entity
	{
		namespace Abstraction
		{
			/// <summary>
			/// Abstract class that represents an entity that can be graphically rendered in the game.
			/// </summary>
			class Drawable : public BaseEntity
			{
			public:
				Drawable();
				~Drawable();

				sf::Sprite* sprite() const { return _sprite; }

			protected:
				sf::Sprite* _sprite;

			};
		}
	}
}
