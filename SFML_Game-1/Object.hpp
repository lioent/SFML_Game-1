#pragma once
#include "Mobile.hpp"

namespace Game
{
	namespace Entity
	{
		namespace Abstraction
		{
			/// <summary>
			/// Abstract class that represents an unanimated object in the game.
			/// </summary>
			class Object : public Mobile
			{
			public:
				Object();
				virtual ~Object();

			protected:

			};
		}
	}
}
