#include "Game.hpp"

Game::Game::Game(string name) :
	_graphicManager(),
	_entityManager(),
	_physicManager()
{
	_name = name;
}

Game::Game::~Game()
{
}
