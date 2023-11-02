#include "Rigidbody.h"
#include "Application.h"

CH::Rigidbody::Rigidbody()
{
	_body = CH::Application::GetInstance()->GetPhysics()->GetWorld()->CreateBody(&_bodyDef);
}

CH::Rigidbody::~Rigidbody()
{
}

void CH::Rigidbody::SetType(b2BodyType newType)
{
	_body->SetType(newType);
}

void CH::Rigidbody::SetPosition(b2Vec2 newPosition, float newAngle)
{
	CH::Application::GetEntity(this)->setPosition(newPosition.x * CH::Physics::WorldScale, newPosition.y * CH::Physics::WorldScale);

	if (_body == nullptr) {
		_bodyDef.position = newPosition;
		_bodyDef.angle = newAngle;
	}
	else {

		_body->SetTransform(newPosition, newAngle);
	}
}

void CH::Rigidbody::SetLinearVelocity(b2Vec2 newLinearVelocity)
{
	if (_body == nullptr) {
		_bodyDef.linearVelocity = newLinearVelocity;
	}
	else {
		_body->SetLinearVelocity(newLinearVelocity);
	}
}

void CH::Rigidbody::SetAngularVelocity(float newAngularVelocity)
{
	if (_body == nullptr) {
		_bodyDef.angularVelocity = newAngularVelocity;
	}
	else {
		_body->SetAngularVelocity(newAngularVelocity);
	}
}

b2Vec2 CH::Rigidbody::GetPosition()
{
	if (_body == nullptr) {
		return _bodyDef.position;
	}
	else {
		return _body->GetTransform().p;
	}
}

float CH::Rigidbody::GetAngle()
{
	if (_body == nullptr) {
		return _bodyDef.angle;
	}
	else {
		return _body->GetAngle();
	}
}

b2Vec2 CH::Rigidbody::GetLinearVelocity()
{
	if (_body == nullptr) {
		return _bodyDef.linearVelocity;
	}
	else {
		return _body->GetLinearVelocity();
	}
}

float CH::Rigidbody::GetAngularVelocity()
{
	if (_body == nullptr) {
		return _bodyDef.angularVelocity;
	}
	else {
		return _body->GetAngularVelocity();
	}
}

b2Body* CH::Rigidbody::GetBody()
{
	if (_body == nullptr) {
		return _body = CH::Application::GetInstance()->GetPhysics()->GetWorld()->CreateBody(&_bodyDef);
	}
	else {
		return _body;
	}
}
