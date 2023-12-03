#include "Application.h"
#include "RessourceManager.h"
#include "Camera.h"
#include "SpriteRenderer.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "FontManager.h"

CH::Application* CH::Application::_instance = nullptr;

CH::Application::Application()
{
	_instance = this;
}

CH::Application::~Application()
{
}

void CH::Application::Init(int sizeX = 800, int sizeY = 600, std::string windowName = "Chrono2DEngine")
{
	RessourceManager::GetInstance()->Init();

	InputManager::GetInstance()->Init();
	AudioManager::GetInstance()->Init();
	FontManager::GetInstance()->Init();

	Window.create(sf::VideoMode(sizeX, sizeY), windowName);
	Window.setFramerateLimit(144);

}

void CH::Application::Loop()
{
	for (Entity* entity : _entities) {
		entity->Awake();
	}

	for (Entity* entity : _entities) {
		entity->Start();
	}

	sf::Clock clock;
	while (Window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				Window.close();
			}
		}

		CH::InputManager::GetInstance()->DoInput();

		for (Entity* entity : _entities) {
			entity->Update(deltaTime);
		}

		for (Entity* entity : _entities) {
			entity->LateUpdate(deltaTime);
		}

		_physics.Update(deltaTime);

		Window.clear();

		for (Entity* entity : _entities) {
			Window.draw(*entity);
		}

		Window.display();
	}
}


CH::Entity* CH::Application::CreateEntity(std::string name)
{
	Entity* entity = new Entity(name);

	_entities.push_back(entity);

	return entity;
}


void CH::Application::SetView(sf::View& newView)
{
	Window.setView(newView);
}

CH::Application* CH::Application::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new Application();
	}

	return _instance;
}

//TODO Random string
std::string CH::Application::GenerateID()
{
	return "Coucou";
}

CH::Entity* CH::Application::GetEntity(Component* component)
{
	auto app = GetInstance();

	for (Entity* entity : app->_entities) {
		for (Component* entityComponent : entity->Components) {
			if (entityComponent == component) {
				return entity;
			}
		}
	}

	return nullptr;
}

std::vector<CH::Entity*> CH::Application::GetEntities()
{
	return _entities;
}

CH::Physics* CH::Application::GetPhysics()
{
	return &_physics;
}




