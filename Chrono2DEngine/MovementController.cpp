#include "MovementController.h"
#include "Application.h"
#include "InputManager.h"
#include "Rigidbody.h"

void CH::MovementController::SetupBind(std::string inputLeft, std::string inputUp, std::string inputDown, std::string inputRight)
{
	_inputLeft = inputLeft;
	_inputRight = inputRight;
	_inputDown = inputDown;
	_inputUp = inputUp;
}

void CH::MovementController::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}

void CH::MovementController::Update(float deltaTime)
{
	CH::Entity* thisEntity = CH::Application::GetInstance()->GetEntity(this);

	if (_inputLeft != "") {
		if (CH::InputManager::GetInstance()->GetInput(_inputLeft)) {
			for (auto component : thisEntity->Components) {
				CH::Rigidbody* rigidbody = dynamic_cast<CH::Rigidbody*>(component);

				if (rigidbody) {

					rigidbody->ApplyForce(b2Vec2(-(1 * _speed), 0));
				}
			}
		}
	}

	if (_inputRight != "") {
		if (CH::InputManager::GetInstance()->GetInput(_inputRight)) {
			for (auto component : thisEntity->Components) {
				CH::Rigidbody* rigidbody = dynamic_cast<CH::Rigidbody*>(component);

				if (rigidbody) {
					rigidbody->ApplyForce(b2Vec2(1 * _speed, 0));
				}
			}
		}
	}

	if (_inputUp != "") {
		if (CH::InputManager::GetInstance()->GetInput(_inputUp)) {
			for (auto component : thisEntity->Components) {
				CH::Rigidbody* rigidbody = dynamic_cast<CH::Rigidbody*>(component);

				if (rigidbody) {
					rigidbody->ApplyForce(b2Vec2(0, -(1 * _speed)));
				}
			}
		}
	}

	if (_inputDown != "") {
		if (CH::InputManager::GetInstance()->GetInput(_inputDown)) {
			for (auto component : thisEntity->Components) {
				CH::Rigidbody* rigidbody = dynamic_cast<CH::Rigidbody*>(component);

				if (rigidbody) {
					rigidbody->ApplyForce(b2Vec2(0, (1 * _speed)));
				}
			}
		}
	}
}
