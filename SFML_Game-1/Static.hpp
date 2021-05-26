#pragma once
#include "Solid.hpp"

using namespace Game::Entity::Abstraction;

namespace Game
{
	namespace Entity
	{
		namespace Abstraction
		{
			/// <summary>
			/// Abstract class that represents an entity that is not affected by game's physics other than collision.
			/// </summary>
			class Static : public Solid
			{
			public:
				Static();
				virtual ~Static();

			protected:

			};
		}
	}
}
