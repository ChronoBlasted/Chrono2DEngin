#include "Entity.h"
#include "Application.h"

CH::Entity::Entity(std::string name)
{
	_name = name;
	_uuid = Application::GetInstance()->GenerateID();
}

CH::Entity::~Entity()
{
}

void CH::Entity::Awake()
{
	for (Component* component : Components) {
		component->Awake();
	}
}

void CH::Entity::Start()
{
	for (Component* component : Components) {
		component->Start();
	}
}

void CH::Entity::Update(float deltaTime)
{
	for (Component* component : Components) {
		component->Update(deltaTime);
	}
}

void CH::Entity::LateUpdate(float deltaTime)
{
	for (Component* component : Components) {
		component->LateUpdate(deltaTime);
	}
}

void CH::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(getTransform());

	for (auto component : Components) {
		sf::Drawable* drawablePtr = dynamic_cast<sf::Drawable*>(component);

		if (drawablePtr) {
			target.draw(*drawablePtr, states);
		}
	}
}

std::string CH::Entity::GetId()
{
	return _uuid;
}

std::string CH::Entity::GetName()
{
	return _name;
}