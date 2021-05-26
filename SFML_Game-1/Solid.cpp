#include "Solid.hpp"

Game::Entity::Abstraction::Solid::Solid() :
	BaseEntity()
{
	this->_rigidBody = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
}
Game::Entity::Abstraction::Solid::Solid(sf::RectangleShape rigidBody) :
	BaseEntity()
{
	this->_rigidBody = new sf::RectangleShape(rigidBody.getSize());
	this->_rigidBody->setFillColor(rigidBody.getFillColor());
	this->_rigidBody->setOrigin(rigidBody.getOrigin());
}
Game::Entity::Abstraction::Solid::~Solid()
{
	delete (_rigidBody);
}
