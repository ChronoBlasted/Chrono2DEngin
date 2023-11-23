#pragma once
#include "Component.h"

namespace CH {
	class MovementController : public CH::Component
	{
	public:
		void SetupBind(std::string inputLeft, std::string inputUp, std::string inputDown, std::string inputRight);
		void SetSpeed(float newSpeed);

		void Update(float deltaTime) override;
	protected:
		float _speed = 10;

		std::string _inputLeft;
		std::string _inputUp;
		std::string _inputDown;
		std::string _inputRight;
	private:
	};
}


