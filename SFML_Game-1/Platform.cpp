#include "Platform.hpp"

Game::Entity::Platform::Platform() :
	Static(),
	Drawable()
{
	this->_rigidBody = new sf::RectangleShape();
	this->_rigidBody->setSize(sf::Vector2f(1000.0f, 200.0f));
	this->_rigidBody->setFillColor(sf::Color{ 200,200,200 });
}
Game::Entity::Platform::~Platform()
{
	delete (this->_rigidBody);
}

#pragma region Actions
void Game::Entity::Platform::position(sf::Vector2f position)
{
	this->_rigidBody->setPosition(position);
}

void Game::Entity::Platform::size(sf::Vector2f size)
{
	this->_rigidBody->setSize(size);
}
#pragma endregion
