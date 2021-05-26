#pragma once
#include <SFML/Graphics.hpp>

namespace Game
{
	namespace Entity
	{
		namespace Interface
		{
			/// <summary>
			/// Interface of a mobile entity.
			/// </summary>
			class IMobile
			{
			public:
				virtual ~IMobile() { }

				virtual void update() = 0;
				virtual void move() = 0;
				virtual void addForce(sf::Vector2f direction) = 0;
			};
		}
	}
}
