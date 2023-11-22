#include <SFML/Graphics.hpp>
#include <iostream>
#include <Chrono2DEngine/Application.h>
#include <Chrono2DEngine/SpriteRenderer.h>
#include <Chrono2DEngine/Camera.h>
#include <Chrono2DEngine/Rigidbody.h>
#include <Chrono2DEngine/BoxCollider.h>
#include <Chrono2DEngine/CollisionChecker.h>
#include <Chrono2DEngine/TextMeshPro.h>

int main()
{
	CH::Application* app = new CH::Application();

	app->Init(2000, 1000, "Chrono2DEngine");

	CH::Entity* groundEntity = app->CreateEntity("Ground");
	//CH::SpriteRenderer* spriteRendererSquare = app->CreateComponent<CH::SpriteRenderer>(*groundEntity);
	//spriteRendererSquare->SetTexture("Square");

	CH::TextMeshPro* textMeshPro = app->CreateComponent<CH::TextMeshPro>(*groundEntity);
	std::string str1 = "Square";
	textMeshPro->SetString(str1);

	CH::Rigidbody* groundRigidbody = app->CreateComponent<CH::Rigidbody>(*groundEntity);
	b2Vec2 groundPos;
	groundPos.Set(0.0f, 400.0f);

	groundRigidbody->SetPosition(groundPos, 0);

	CH::BoxCollider* groundBoxCollider = app->CreateComponent<CH::BoxCollider>(*groundEntity);
	groundBoxCollider->SetSize(256, 256);

	groundBoxCollider->CreateFixture(groundRigidbody->GetBody());



	CH::Entity* circleEntity = app->CreateEntity("Circle");
	CH::SpriteRenderer* spriteRendererBall = app->CreateComponent<CH::SpriteRenderer>(*circleEntity);
	spriteRendererBall->SetTexture("Circle");

	CH::Camera* gameView = app->CreateComponent<CH::Camera>(*circleEntity);
	gameView->SetFollow(circleEntity);
	gameView->SetZoom(2);

	CH::Rigidbody* circleRigidbody = app->CreateComponent<CH::Rigidbody>(*circleEntity);
	b2Vec2 circlePos;
	circlePos.Set(0, 0);
	circleRigidbody->SetPosition(circlePos, 0);
	circleRigidbody->SetType(b2_dynamicBody);

	CH::BoxCollider* circleBoxCollider = app->CreateComponent<CH::BoxCollider>(*circleEntity);
	circleBoxCollider->SetSize(256, 256);
	circleBoxCollider->SetDensity(1);
	circleBoxCollider->SetFriction(.3f);

	circleBoxCollider->CreateFixture(circleRigidbody->GetBody());

	CH::CollisionChecker* collisionChecker = app->CreateComponent<CH::CollisionChecker>(*circleEntity);

	app->Loop();

	return 0;
}