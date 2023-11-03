#pragma once
#include "Component.h"
#include "ICollisionable.h"

namespace CH {
	class CollisionChecker : public CH::Component, public CH::ICollisionable
	{
	public:
		void BeginCollision() override;
		void EndCollision() override;
	protected:
	private:
	};
}


