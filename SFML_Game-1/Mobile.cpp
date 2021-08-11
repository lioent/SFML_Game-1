#include "Mobile.hpp"


Game::Entity::Abstraction::Mobile::Mobile() :
	Solid(),
	max_acceleration(10.0f)
{
	//this->_speed = 0.0f;
	this->_speed = sf::Vector2f(0.0f, 0.0f);
	this->_acceleration = sf::Vector2f(0.0f, 0.0f);
	this->_mass = 20.0f;
}

Game::Entity::Abstraction::Mobile::~Mobile()
{

}

#pragma region Actions
void Game::Entity::Abstraction::Mobile::move()
{
	Solid::rigidBody()->move(
		this->speed()
	);
}

void Game::Entity::Abstraction::Mobile::addForce(sf::Vector2f direction)
{
	// F = m * a
	// a = F / m;
	_acceleration += direction;

	// Acceleration limit
	if (_acceleration.x > max_acceleration)
		_acceleration.x = max_acceleration;
	else if (_acceleration.x < -max_acceleration)
		_acceleration.x = -max_acceleration;
	if (_acceleration.y > max_acceleration)
		_acceleration.y = max_acceleration;
	else if (_acceleration.y < -max_acceleration)
		_acceleration.y = -max_acceleration;
}
#pragma endregion
