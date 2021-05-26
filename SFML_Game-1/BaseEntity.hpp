#pragma once

namespace Game
{
	namespace Entity
	{
		/// <summary>
		/// Abstract class that represents all entities.
		/// </summary>
		class BaseEntity
		{
		public:
			BaseEntity();
			~BaseEntity();

			unsigned int id() const { return _id; }
			void id(const unsigned int id) { _id = id; }

		private:
			unsigned int _id;

		};
	}
}
