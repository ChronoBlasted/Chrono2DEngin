#include <SFML/Graphics.hpp>
#include <iostream>
#include <Chrono2DEngine/Application.h>
#include <Chrono2DEngine/AudioClip.h>
#include <Chrono2DEngine/AudioManager.h>
#include <Chrono2DEngine/SpriteRenderer.h>
#include <Chrono2DEngine/Camera.h>
#include <Chrono2DEngine/Rigidbody.h>
#include <Chrono2DEngine/BoxCollider.h>
#include <Chrono2DEngine/CollisionChecker.h>
#include <Chrono2DEngine/TextMeshPro.h>
#include <Chrono2DEngine/InputManager.h>
#include <Chrono2DEngine/MovementController.h>
#include "BlastOfBlade.h"
#include <Chrono2DEngine/Spawner.h>

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
#pragma region Bounds

	CreateStaticEntity(app, "TopGrass", 0, 128, 48, 1);
	CreateStaticEntity(app, "OrangeCube", 423, -96, 1, 24);
	CreateStaticEntity(app, "OrangeCube", -423, -96, 1, 24);
	CreateStaticEntity(app, "OrangeCube", 0, -321, 48, 1);

#pragma endregion
#pragma region Enemy
	CH::Entity* spanerEntity = app->CreateEntity("Spawner");
	CH::Spawner* enemySpawner = app->CreateComponent<CH::Spawner>(*spanerEntity);
	enemySpawner->spawnInterval = sf::seconds(1);

#pragma endregion
#pragma region Audio

	CH::AudioManager::GetInstance()->PlayMusic("Menu");

#pragma endregion
#pragma region Player
	CH::Entity* playerEntity = CreatePlayer(app);
	CreateCamera(app, playerEntity);
#pragma endregion

	app->Loop();

	return 0;
}

void CreateCamera(CH::Application* app, CH::Entity* playerEntity)
{

	CH::Camera* gameView = app->CreateComponent<CH::Camera>(*playerEntity);
	gameView->SetFollow(playerEntity);
	gameView->SetZoom(.5f);

	CH::TextMeshPro* textMeshPro = app->CreateComponent<CH::TextMeshPro>(*playerEntity);
	textMeshPro->SetString("Score : 0");
	textMeshPro->SetPosition(-448, -256);
}
CH::Entity* CreatePlayer(CH::Application* app)
{
	CH::Entity* playerEntity = app->CreateEntity("Player");
	CH::SpriteRenderer* playerSprite = app->CreateComponent<CH::SpriteRenderer>(*playerEntity);
	playerSprite->SetTexture("Player");
	playerSprite->SetOrigin(12, 12);


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
	movementController->SetSpeed(100000);

	return playerEntity;
}


void CreateStaticEntity(CH::Application* app, std::string spriteName, int posX, int posY, int sizeX, int sizeY)
{
	CH::Entity* entity = app->CreateEntity(spriteName);

	CH::SpriteRenderer* spriteRenderer = app->CreateComponent<CH::SpriteRenderer>(*entity);
	spriteRenderer->SetTexture(spriteName);
	spriteRenderer->SetRepeated(true);
	spriteRenderer->UpdateSize(1 * sizeX, 1 * sizeY);
	spriteRenderer->SetOrigin(spriteRenderer->GetSprite()->getLocalBounds().getSize().x / 2, spriteRenderer->GetSprite()->getLocalBounds().getSize().y / 2);

	CH::Rigidbody* rigidbody = app->CreateComponent<CH::Rigidbody>(*entity);
	b2Vec2 groundPos;
	groundPos.Set(posX, posY);
	rigidbody->SetPosition(groundPos, 0);

	CH::BoxCollider* boxCollider = app->CreateComponent<CH::BoxCollider>(*entity);
	boxCollider->SetSize(18 * sizeX, 18 * sizeY);

	boxCollider->CreateFixture(rigidbody->GetBody());
}
