#pragma once
#include "Collider.h"

namespace CH {
	class BoxCollider : public CH::Collider
	{
	public:
		BoxCollider();
		~BoxCollider();

		b2Shape* GetShape() override;

		void SetSize(float width, float height);
	protected:
		b2PolygonShape _shape;
		float _width;
		float _height;
	private:
	};
}