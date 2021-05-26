#include "EntityManager.hpp"

Game::Manager::EntityManager::EntityManager() { }
Game::Manager::EntityManager::~EntityManager() { }

#pragma region Actions
void Game::Manager::EntityManager::update(Mobile& entity, float deltaTime)
{
	entity.update();
}
#pragma endregion
