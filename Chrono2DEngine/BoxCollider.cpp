#include "BoxCollider.h"

CH::BoxCollider::BoxCollider() : _width(1), _height(1)
{
	_shape.SetAsBox(_width / 2, _height / 2);
}

CH::BoxCollider::~BoxCollider()
{
}

b2Shape* CH::BoxCollider::GetShape()
{
	_shape.SetAsBox(_width / 2, _height / 2);

	return &_shape;
}

void CH::BoxCollider::SetSize(float width, float height)
{
	_width = width;
	_height = height;

	_shape.SetAsBox(_width / 2, _height / 2);
}
