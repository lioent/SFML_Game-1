#pragma once
#include <SFML/Graphics.hpp>
#include "BaseEntity.hpp"

namespace Game
{
	namespace Entity
	{
		namespace Abstraction
		{
			/// <summary>
			/// Abstract class that represents an entity affected by game's physics.
			/// </summary>
			class Solid : public BaseEntity
			{
			public:
				Solid();
				Solid(sf::RectangleShape rigidBody);
				virtual ~Solid();

				sf::RectangleShape* rigidBody() { return _rigidBody; }

			protected:
				sf::RectangleShape* _rigidBody;

			};
		}
	}
}
