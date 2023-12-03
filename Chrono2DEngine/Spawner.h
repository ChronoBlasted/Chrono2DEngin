#pragma once
#include "Component.h"
#include "Entity.h"

namespace CH {
	class Spawner : public CH::Component
	{
	public:
		Entity* ObjectToSpawn;

		void Update(float deltaTime) override;

		void SpawnObject();
		void SpawnEnemy();

		sf::Time spawnInterval;
	protected:
	private:
		sf::Clock clock;

		sf::Time timer;
	};
}