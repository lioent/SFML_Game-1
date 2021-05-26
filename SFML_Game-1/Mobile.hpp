#pragma once
#include <SFML/Graphics.hpp>
#include "IMobile.hpp"
#include "Solid.hpp"

using namespace Game::Entity::Interface;

namespace Game
{
	namespace Entity
	{
		namespace Abstraction
		{
			/// <summary>
			/// Abstract class that represents a solid that can move itself.
			/// </summary>
			class Mobile : public IMobile, public Solid
			{
			public:
				Mobile();
				~Mobile();

				virtual void update() {};
				virtual void move() {}

				void addForce(sf::Vector2f direction);

				float mass() const { return this->_mass; }
				void mass(const float mass) { this->_mass = mass; }

				sf::Vector2f speed() const { return this->_speed; }
				void speed(const sf::Vector2f speed) { this->_speed = speed; }
				void speed(const float x, const float y) { this->_speed.x = x; this->_speed.y = y; }
				void speedX(const float x) { this->_speed.x = x; }
				void speedY(const float y) { this->_speed.y = y; }

				sf::Vector2f acceleration() const { return _acceleration; }
				void acceleration(const sf::Vector2f acceleration) { _acceleration = acceleration; }
				void acceleration(const float x, const float y) { this->_acceleration.x = x; this->_acceleration.y = y; }
				void accelerationX(const float x) { this->_acceleration.x = x; }
				void accelerationY(const float y) { this->_acceleration.y = y; }

			protected:
				float _mass;
				sf::Vector2f _speed;
				sf::Vector2f _acceleration;

				const float max_acceleration;

			};
		}
	}
}
