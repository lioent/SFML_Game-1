#pragma once
#include <SFML/Graphics.hpp>

using std::string;

namespace Game
{
	namespace Manager
	{
		/// <summary>
		/// Handles the graphics of the game.
		/// </summary>
		class GraphicManager
		{
		public:
			GraphicManager(sf::RenderWindow* window = nullptr);
			~GraphicManager();

			void openWindow(
				sf::VideoMode videoMode = sf::VideoMode(1366, 768), 
				string name = "", sf::Uint32 style = 
				sf::Style::Default
			);

			sf::RenderWindow* window() const { return _window; }

		private:
			sf::RenderWindow* _window;
		};
	}
}
