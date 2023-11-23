#include <SFML/Graphics.hpp>
#include <iostream>
#include <Chrono2DEngine/Application.h>
#include <Chrono2DEngine/SpriteRenderer.h>
#include <Chrono2DEngine/Camera.h>
#include <Chrono2DEngine/Rigidbody.h>
#include <Chrono2DEngine/BoxCollider.h>
#include <Chrono2DEngine/CollisionChecker.h>
#include <Chrono2DEngine/TextMeshPro.h>
#include <Chrono2DEngine/InputManager.h>
#include <Chrono2DEngine/MovementController.h>

int main()
{
#pragma region Initialization
	CH::Application* app = new CH::Application();

	app->Init(1920, 1080, "Chrono2DEngine");
#pragma endregion
#pragma region Input
	CH::Input* MoveUpInput = new CH::Input();
	MoveUpInput->SetBind(sf::Keyboard::Z);
	CH::InputManager::GetInstance()->AddInput("MoveUp", MoveUpInput);

	CH::Input* MoveRightInput = new CH::Input();
	MoveRightInput->SetBind(sf::Keyboard::D);
	CH::InputManager::GetInstance()->AddInput("MoveRight", MoveRightInput);

	CH::Input* MoveLeftInput = new CH::Input();
	MoveLeftInput->SetBind(sf::Keyboard::Q);
	CH::InputManager::GetInstance()->AddInput("MoveLeft", MoveLeftInput);

	CH::Input* MoveDownInput = new CH::Input();
	MoveDownInput->SetBind(sf::Keyboard::S);
	CH::InputManager::GetInstance()->AddInput("MoveDown", MoveDownInput);

	CH::Input* LeftClick = new CH::Input();
	LeftClick->SetBind(sf::Mouse::Left);
	CH::InputManager::GetInstance()->AddInput("LeftClick", LeftClick);

	CH::Input* RightClick = new CH::Input();
	RightClick->SetBind(sf::Mouse::Right);
	CH::InputManager::GetInstance()->AddInput("RightClick", RightClick);
#pragma endregion

	// Ground

	CH::Entity* groundEntity = app->CreateEntity("Ground");

	CH::SpriteRenderer* spriteRendererSquare = app->CreateComponent<CH::SpriteRenderer>(*groundEntity);
	spriteRendererSquare->SetTexture("TopGrass");
	spriteRendererSquare->UpdateSize(10, 1);
	spriteRendererSquare->SetRepeated(true);

	CH::Rigidbody* groundRigidbody = app->CreateComponent<CH::Rigidbody>(*groundEntity);
	b2Vec2 groundPos;
	groundPos.Set(0.0f, 200);
	groundRigidbody->SetPosition(groundPos, 0);

	CH::BoxCollider* groundBoxCollider = app->CreateComponent<CH::BoxCollider>(*groundEntity);
	groundBoxCollider->SetSize(24, 24);

	groundBoxCollider->CreateFixture(groundRigidbody->GetBody());

	// Player

	CH::Entity* playerEntity = app->CreateEntity("Circle");
	CH::SpriteRenderer* playerSprite = app->CreateComponent<CH::SpriteRenderer>(*playerEntity);
	playerSprite->SetTexture("Player");

	CH::Rigidbody* playerRb = app->CreateComponent<CH::Rigidbody>(*playerEntity);
	b2Vec2 playerPos;
	playerPos.Set(0, 0);
	playerRb->SetPosition(playerPos, 0);
	playerRb->SetType(b2_dynamicBody);

	CH::BoxCollider* circleBoxCollider = app->CreateComponent<CH::BoxCollider>(*playerEntity);
	circleBoxCollider->SetSize(24, 24);
	circleBoxCollider->SetDensity(1);
	circleBoxCollider->SetFriction(.3f);

	circleBoxCollider->CreateFixture(playerRb->GetBody());

	CH::CollisionChecker* collisionChecker = app->CreateComponent<CH::CollisionChecker>(*playerEntity);
	CH::MovementController* movementController = app->CreateComponent<CH::MovementController>(*playerEntity);

	movementController->SetupBind("MoveLeft", "MoveUp", "MoveDown", "MoveRight");
	movementController->SetSpeed(1000000);



	// Camera

	CH::Camera* gameView = app->CreateComponent<CH::Camera>(*playerEntity);
	gameView->SetFollow(playerEntity);
	gameView->SetZoom(.5f);

	CH::TextMeshPro* textMeshPro = app->CreateComponent<CH::TextMeshPro>(*playerEntity);
	textMeshPro->SetString("Score : ");
	textMeshPro->SetPosition(-448, -256);

	app->Loop();

	return 0;
}