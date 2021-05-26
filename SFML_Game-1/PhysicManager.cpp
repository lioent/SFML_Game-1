#include "PhysicManager.hpp"
#include <iostream>

const float Game::Manager::PhysicManager::GRAVITY = 981.0f;
const float Game::Manager::PhysicManager::DECELERATION_RATE = 0.93f;

Game::Manager::PhysicManager::PhysicManager() { }
Game::Manager::PhysicManager::~PhysicManager() { }

#pragma region Actions
/// <summary>
/// Updates the state of a mobile entity by applying physic effects to it.
/// </summary>
/// <param name="entity">Mobile entity to be updated</param>
/// <param name="deltaTime">Time difference since last game loop</param>
void Game::Manager::PhysicManager::update(Mobile& entity, float deltaTime)
{
	applyDeceleration(entity, deltaTime);
	applyGravity(entity, deltaTime);
}

/// <summary>
/// Applies gravity rules to the mobile entity.
/// </summary>
/// <param name="entity">Mobile entity that will be affected by gravity</param>
/// <param name="deltaTime">Time difference since last game loop</param>
void Game::Manager::PhysicManager::applyGravity(Mobile& entity, float deltaTime)
{
	entity.speedY(entity.speed().y + (981.0f * deltaTime));
}

/// <summary>
/// Reduces the acceleration of a mobile entity to zero.
/// </summary>
/// <param name="entity">Mobile entity to be slowed down</param>
/// <param name="deltaTime">Time difference since last game loop</param>
void Game::Manager::PhysicManager::applyDeceleration(Mobile& entity, float deltaTime)
{
	// Essentially applies deacceleration
	entity.acceleration(
		entity.acceleration().x * DECELERATION_RATE,
		entity.acceleration().y * DECELERATION_RATE
	);

	// If near zero, stop
	if (entity.speed().x <= 0.1f || entity.speed().x >= -0.1f)
		entity.speedX(0.0f);
	if (entity.speed().y <= 0.1f || entity.speed().y >= -0.1f)
		entity.speedY(0.0f);

}
#pragma endregion
