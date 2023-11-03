#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "pch.h"
#include "Entity.h"
#include "Physics.h"
#include "LuaScript.h"

namespace CH {
	class Application
	{
	public:
		sf::RenderWindow Window;

		Application();
		~Application();

		void Init(int sizeX, int sizeY, std::string windowName);
		void Loop();
		void SetView(sf::View& newView);

		Entity* CreateEntity(std::string name);

		template<typename T>
		T* CreateComponent(Entity& entity)
		{
			T* componentToAdd = new T();

			entity.Components.push_back(componentToAdd);

			return componentToAdd;
		}

		static Application* GetInstance();
		static std::string GenerateID();
		static Entity* GetEntity(Component* component);

		std::vector<CH::Entity*> GetEntities();
		Physics* GetPhysics();
	protected:
		std::vector<CH::Entity*> _entities;
		Physics _physics;
		LuaScript _luaScript;
		static Application* _instance;
	};
}


