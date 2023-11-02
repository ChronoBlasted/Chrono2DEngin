#include <Box2D/box2d.h>
#include "Component.h"

#pragma once
namespace CH {
	class Collider : public CH::Component
	{
	public:
		Collider();
		~Collider();

		void CreateFixture(b2Body* newRigidbody);
		virtual b2Shape* GetShape() = 0;

		void SetDensity(float newDensity);
		void SetFriction(float newFriction);
	protected:
		b2FixtureDef _fixtureDef;
		b2Fixture* _fixture;
	private:
	};
}