#include "CollisionListener.h"
#include "Collision.h"
#include "CollisionChecker.h"
#include "Application.h"

void CH::CollisionListener::BeginContact(b2Contact* contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();

	for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
		for (Component* component : entity->Components) {

			Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);

			if (currentRb) {

				if (currentRb->GetBody() == bodyA) {
					for (Component* componentInEntityOfRigidbody : entity->Components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->BeginCollision();
						}
					}
				}
			}
		}
	}

	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
		for (Component* component : entity->Components) {

			Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);

			if (currentRb) {

				if (currentRb->GetBody() == bodyB) {
					for (Component* componentInEntityOfRigidbody : entity->Components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->BeginCollision();
						}
					}
				}
			}
		}
	}

	//Collision
}

void CH::CollisionListener::EndContact(b2Contact* contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();

	for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
		for (Component* component : entity->Components) {

			Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);


			if (currentRb) {

				if (currentRb->GetBody() == bodyA) {
					for (Component* componentInEntityOfRigidbody : entity->Components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->EndCollision();
						}
					}
				}
			}
		}
	}

	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	for (Entity* entity : CH::Application::GetInstance()->GetEntities()) {
		for (Component* component : entity->Components) {

			Rigidbody* currentRb = dynamic_cast<Rigidbody*>(component);


			if (currentRb) {

				if (currentRb->GetBody() == bodyB) {
					for (Component* componentInEntityOfRigidbody : entity->Components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->EndCollision();
						}
					}
				}
			}
		}
	}
}