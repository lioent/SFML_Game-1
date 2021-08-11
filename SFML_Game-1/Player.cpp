#include "Player.hpp"



Game::Entity::Player::Player() : Mobile(), Drawable() { }
Game::Entity::Player::~Player() { }

#pragma region Actions
/// <summary>
/// Updates the Player's state.
/// </summary>
void Game::Entity::Player::update()
{
	updateAcceleration();
	move();
}

/// <summary>
/// Moves the Player's body according to their current speed and acceleration.
/// </summary>
void Game::Entity::Player::move()
{
	this->_speed.x += this->_acceleration.x;
	this->_speed.y += this->_acceleration.y;

	Mobile::move();
}
#pragma endregion

#pragma region Auxiliary Methods
/// <summary>
/// Updates the Player's acceleration
/// </summary>
void Game::Entity::Player::updateAcceleration()
{
	// X axis
	if (leftMovementKeyIsPressed())
		this->addForce(sf::Vector2f(-1.0f, 0.0f));
	else if (rightMovementKeyIsPressed())
		this->addForce(sf::Vector2f(1.0f, 0.0f));

	// Y axis
	if (upMovementKeyIsPressed())
		this->addForce(sf::Vector2f(0.0f, -1.0f));
	else if (downMovementKeyIsPressed())
		this->addForce(sf::Vector2f(0.0f, 1.0f));
}

/// <summary>
/// Signals whether the Player is being moved upwards or not.
/// </summary>
/// <returns>true if the Player is moving upwards or false if it is not</returns>
bool Game::Entity::Player::upMovementKeyIsPressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

/// <summary>
/// Signals whether the Player is being moved left or not.
/// </summary>
/// <returns>true if the Player is moving left or false if it is not</returns>
bool Game::Entity::Player::leftMovementKeyIsPressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
}

/// <summary>
/// Signals whether the Player is being moved down or not.
/// </summary>
/// <returns>true if the Player is moving down or false if it is not</returns>
bool Game::Entity::Player::downMovementKeyIsPressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}

/// <summary>
/// Signals whether the Player is being moved right or not.
/// </summary>
/// <returns>true if the Player is moving right or false if it is not</returns>
bool Game::Entity::Player::rightMovementKeyIsPressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}
#pragma endregion
