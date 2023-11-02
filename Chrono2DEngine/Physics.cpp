#include "Physics.h"
#include "Application.h"
#include "Rigidbody.h"
#include "Collider.h"


CH::Physics::Physics() : _gravity(0, 10), _world(_gravity)
{
}

CH::Physics::~Physics()
{
}

void CH::Physics::Update(float deltaTime)
{
	for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
		for (Component* component : entity->Components) {

			Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);

			if (currentRb) {
				b2Vec2 graphPos;
				graphPos.Set(entity->getPosition().x / WorldScale, entity->getPosition().y / WorldScale);

				currentRb->SetPosition(graphPos, entity->getRotation());
			}
		}

		_world.Step(deltaTime, 6, 2);

		for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
			for (Component* component : entity->Components) {
				Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);

				if (currentRb) {

					sf::Vector2f worldPos;
					worldPos.x = currentRb->GetPosition().x * WorldScale;
					worldPos.y = currentRb->GetPosition().y * WorldScale;

					entity->setPosition(worldPos);
				}
			}
		}
	}
}

b2World* CH::Physics::GetWorld()
{
	return &_world;
}
