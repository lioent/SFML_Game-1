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

				sf::Vector2f position() const { return this->_rigidBody->getPosition(); }
				void position(const sf::Vector2f position) { this->_rigidBody->setPosition(position); }
				
				sf::Vector2f size() const { return this->_rigidBody->getSize(); }
				void size(const sf::Vector2f size) { this->_rigidBody->setSize(size); }

			protected:
				sf::RectangleShape* _rigidBody;

			};
		}
	}
}
