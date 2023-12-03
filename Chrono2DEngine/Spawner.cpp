#include "Spawner.h"
#include "Application.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"
#include "BoxCollider.h"
#include "CollisionChecker.h"

void CH::Spawner::Update(float deltaTime)
{
	timer += sf::seconds(deltaTime);

	if (timer >= spawnInterval) {
		SpawnEnemy();
		timer -= spawnInterval;
	}
}

void CH::Spawner::SpawnObject()
{
	if (ObjectToSpawn != nullptr) {
		CH::Entity* entityPtr = CH::Application::GetInstance()->CreateEntity("ObjectToSpawn");
		std::cout << "Object spawned!" << std::endl;
	}
}

void CH::Spawner::SpawnEnemy()
{
	Application* app = CH::Application::GetInstance();

	//CH::Entity* enemyEntity = app->CreateEntity("Enemy");
	//CH::SpriteRenderer* enemySprite = app->CreateComponent<CH::SpriteRenderer>(*enemyEntity);
	//enemySprite->SetTexture("Enemy");
	//enemySprite->SetOrigin(12, 12);


	//CH::Rigidbody* enemyRb = app->CreateComponent<CH::Rigidbody>(*enemyEntity);
	//b2Vec2 enemyPos;
	//enemyPos.Set(0, 0); //Set random X
	//enemyRb->SetPosition(enemyPos, 0);
	//enemyRb->SetType(b2_dynamicBody);

	//CH::BoxCollider* circleBoxCollider = app->CreateComponent<CH::BoxCollider>(*enemyEntity);
	//circleBoxCollider->SetSize(24, 24);
	//circleBoxCollider->SetDensity(1);
	//circleBoxCollider->SetFriction(.3f);

	//circleBoxCollider->CreateFixture(enemyRb->GetBody());

	//CH::CollisionChecker* collisionChecker = app->CreateComponent<CH::CollisionChecker>(*enemyEntity);

	std::cout << "Object spawned!" << std::endl;

}
