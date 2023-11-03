#include "Collider.h"

CH::Collider::Collider()
{
}

CH::Collider::~Collider()
{
}

void CH::Collider::CreateFixture(b2Body* newRigidbody)
{
	_fixtureDef.shape = GetShape();

	_fixture = newRigidbody->CreateFixture(&_fixtureDef);
}

void CH::Collider::SetDensity(float newDensity)
{
	if (_fixture == nullptr) {
		_fixtureDef.density = newDensity;
	}
	else {
		_fixture->SetDensity(newDensity);
	}
}

void CH::Collider::SetFriction(float newFriction)
{
	if (_fixture == nullptr) {
		_fixtureDef.friction = newFriction;
	}
	else {
		_fixture->SetFriction(newFriction);
	}
}

