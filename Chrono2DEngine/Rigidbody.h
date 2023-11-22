#pragma once
#include <Box2D/box2d.h>
#include <SFML/System/Vector2.hpp>
#include "Component.h"

namespace CH {
	class Rigidbody : public CH::Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		void SetType(b2BodyType newType);
		void SetPosition(b2Vec2 newPosition, float newAngle);
		void SetLinearVelocity(b2Vec2 newLinearVelocity);
		void SetAngularVelocity(float newAngularVelocity);

		b2Vec2 GetPosition();
		float GetAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();

		b2Body* GetBody();
	protected:
		b2BodyDef _bodyDef;
		b2Body* _body;
	private:
	};
}


