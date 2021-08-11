#include "MyGame.hpp"

#include "Player.hpp"
#include "Platform.hpp"

using namespace Game::Entity;

#include "iostream"

Game::MyGame::MyGame(string name) :
	Game(name)
{
}

Game::MyGame::~MyGame()
{
}

#pragma region Actions
void Game::MyGame::run()
{
	// Open window
	_graphicManager.openWindow(sf::VideoMode(1366, 786), _name, sf::Style::Default);
	_graphicManager.window()->setFramerateLimit(60);
	//_eventHandler.bindWindowReference(_graphicManager.window());

	// Initialize entities
	Player player = Player();
	player.rigidBody()->setOrigin(
		player.size() / 2.0f
	);
	player.position(sf::Vector2f(200.0f, 100.0f));

	Platform platform1 = Platform();
	platform1.size(sf::Vector2f(500.0f, 100.0f));
	platform1.rigidBody()->setOrigin(
		platform1.size() / 2.0f
	);
	platform1.position(sf::Vector2f(200.0f, 500.0f));

	// Game Loop
	sf::Clock clock;
	while (_graphicManager.window()->isOpen())
	{
		sf::Time deltaTime = clock.restart();

		sf::Event event;
		while (_graphicManager.window()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_graphicManager.window()->close();
			}
		}

		// Update entities
		_entityManager.update(player, deltaTime.asSeconds());
		_physicManager.update(player, deltaTime.asSeconds());
		_physicManager.updateCollision(player, platform1, deltaTime.asSeconds());
		/*std::cout << _physicManager.checkCollision(player, platform1) << std::endl;*/

		// Draw entities
		_graphicManager.window()->clear();
		_graphicManager.window()->draw(*player.rigidBody());
		_graphicManager.window()->draw(*platform1.rigidBody());
		_graphicManager.window()->display();
	}
}

void Game::MyGame::exit()
{
	// save state
	// close game
}
#pragma endregion
