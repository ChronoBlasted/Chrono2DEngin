#pragma once
#include "Rigidbody.h"

namespace CH {
	class Collision {
	public:
		Collision(Rigidbody* me, Rigidbody* other);
		~Collision();

		Rigidbody* GetMyRigidbody();
		Rigidbody* GetOtherRigidbody();

		void SetMeRigidbody(Rigidbody* newMe);
		void SetOtherRigidbody(Rigidbody* newOther);

	protected:
		Rigidbody* _me;
		Rigidbody* _other;
	};
}