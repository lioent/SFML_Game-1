#pragma once
#include "GraphicManager.hpp"
#include "EntityManager.hpp"
#include "PhysicManager.hpp"
#include <string>

using namespace Game::Manager;
using std::string;

namespace Game
{
	/// <summary>
	/// Abstract class that represents the Game itself.
	/// </summary>
	class Game
	{
	public:
		Game(string name = "Game");
		~Game();

		virtual void run() = 0;
		virtual void exit() = 0;

		string name() const { return _name; }
		void name(const string name) { _name = name; }

	protected:
		string _name;
		GraphicManager _graphicManager;
		//EventHandler _eventHandler;
		EntityManager _entityManager;
		PhysicManager _physicManager;

	};
}
