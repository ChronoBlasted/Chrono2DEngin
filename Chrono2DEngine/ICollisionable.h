#pragma once
namespace CH {
	class ICollisionable
	{
	public:
		virtual void BeginCollision() = 0;
		virtual void EndCollision() = 0;
	protected:
	private:
	};
}