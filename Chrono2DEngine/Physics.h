#include <Box2D/box2d.h>
#pragma once
namespace CH {
	class Physics
	{
	public:
		Physics();
		~Physics();

		void Update(float deltaTime);

		inline static float WorldScale = 1;

		b2World* GetWorld();
	protected:
		b2Vec2 _gravity;
		b2World _world;
	private:
	};
}

