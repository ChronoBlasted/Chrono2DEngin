#pragma once
#include <Box2D/box2d.h>

namespace CH {
	class CollisionListener : public b2ContactListener {
	public:
		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}


