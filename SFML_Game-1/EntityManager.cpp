#include "EntityManager.hpp"

Game::Manager::EntityManager::EntityManager() { }
Game::Manager::EntityManager::~EntityManager() { }

#pragma region Actions
/// <summary>
/// Updates the state of a given entity.
/// </summary>
/// <param name="entity"></param>
/// <param name="deltaTime"></param>
void Game::Manager::EntityManager::update(Mobile& entity, float deltaTime)
{
	entity.update();
}
#pragma endregion
