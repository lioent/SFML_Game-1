#include "Drawable.hpp"

Game::Entity::Abstraction::Drawable::Drawable()
	: BaseEntity()
{
	this->_sprite = nullptr;
	//+this->_sprite = new sf::Sprite();
}
Game::Entity::Abstraction::Drawable::~Drawable()
{
	//delete (this->_sprite);
}
