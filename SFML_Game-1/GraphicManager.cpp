#include "GraphicManager.hpp"

Game::Manager::GraphicManager::GraphicManager(sf::RenderWindow* window)
{
	this->_window = window;
}
Game::Manager::GraphicManager::~GraphicManager()
{
	delete (this->_window);
}

#pragma region Actions
void Game::Manager::GraphicManager::openWindow(sf::VideoMode videoMode, string name, sf::Uint32 style)
{
	this->_window = new sf::RenderWindow(videoMode, name, style);
}
#pragma endregion
