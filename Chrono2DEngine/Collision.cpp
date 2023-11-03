#include "Collision.h"
#include <iostream>



CH::Collision::Collision(Rigidbody* me, Rigidbody* other) : _me(me), _other(other)
{
}

CH::Collision::~Collision()
{
}

CH::Rigidbody* CH::Collision::GetMyRigidbody()
{
	return _me;
}

CH::Rigidbody* CH::Collision::GetOtherRigidbody()
{
	return _other;
}

void CH::Collision::SetMeRigidbody(Rigidbody* newMe)
{
	_me = newMe;
}

void CH::Collision::SetOtherRigidbody(Rigidbody* newOther)
{
	_other = newOther;
}


