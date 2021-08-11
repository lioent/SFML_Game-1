#include "PhysicManager.hpp"
#include <iostream>

const float Game::Manager::PhysicManager::GRAVITY = 981.0f;
const float Game::Manager::PhysicManager::DECELERATION_RATE = 0.90f;

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
	applyDeceleration(entity);
	applyGravity(entity, deltaTime);
}

void Game::Manager::PhysicManager::updateCollision(Mobile& entity, Mobile& collider, float deltaTime)
{
	sf::Vector2<bool> collision = checkCollision(entity, collider);
	if (collision.x)
	{
		float force = entity.mass() * entity.acceleration().x;
		entity.addForce(-(force / 10.0f), 0);
		collider.addForce(force / 10.0f, 0);
	}
	else if (collision.y)
	{
		float force = entity.mass() * entity.acceleration().y;
		entity.addForce(0, -(force / 10.0f));
		collider.addForce(0, force / 10.0f);
	}
}

void Game::Manager::PhysicManager::updateCollision(Mobile& entity, Solid& collider, float deltaTime)
{
	sf::Vector2<bool> collision = checkCollision(entity, collider);
	if (collision.x)
	{
		float force = entity.mass() * entity.acceleration().x;
		entity.addForce(-(force / 10.0f), 0);
	}
	else if (collision.y)
	{
		if (abs(entity.acceleration().y) < 5.0f)
		{
			entity.accelerationY(0.0f);
		}
		float force = entity.mass() * entity.acceleration().y;
		entity.addForce(0, -force);
	}
}
#pragma endregion

#pragma region Auxiliary Methods
/// <summary>
/// Applies gravity rules to the mobile entity.
/// </summary>
/// <param name="entity">Mobile entity that will be affected by gravity</param>
/// <param name="deltaTime">Time difference since last game loop</param>
void Game::Manager::PhysicManager::applyGravity(Mobile& entity, float deltaTime)
{
	entity.accelerationY(entity.acceleration().y + (98.1f * deltaTime));
}

/// <summary>
/// Reduces the acceleration of a mobile entity to zero.
/// </summary>
/// <param name="entity">Mobile entity to be slowed down</param>
/// <param name="deltaTime">Time difference since last game loop</param>
void Game::Manager::PhysicManager::applyDeceleration(Mobile& entity)
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

/// <summary>
/// Signals whether the two Solid entities are colliding or not.
/// </summary>
/// <param name="entity">Object that may be colliding</param>
/// <param name="collider">Object that the entity may be colliding with</param>
/// <returns>True for colliding and False for not colliding</returns>
sf::Vector2<bool> Game::Manager::PhysicManager::checkCollision(Solid& entity, Solid& collider)
{
	sf::Vector2f delta = sf::Vector2f(
		collider.position().x - entity.position().x,
		collider.position().y - entity.position().y
	);
	sf::Vector2f intersect = sf::Vector2f(
		abs(delta.x) - ((entity.size().x / 2.0f) + (collider.size().x / 2.0f)),
		abs(delta.y) - ((entity.size().y / 2.0f) + (collider.size().y / 2.0f))
	);

	if (intersect.x < 0.0f && intersect.y < 0.0f)
	{
		// X axis collision
		if (intersect.x > intersect.y)
		{
			return sf::Vector2<bool>(true, false);
		}
		// Y axis collision
		else
		{
			return sf::Vector2<bool>(false, true);
		}
	}

	return sf::Vector2<bool>(false, false);
}
#pragma endregion
