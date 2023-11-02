#pragma once
#include <iostream>
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace CH {
	class Entity : public sf::Transformable, public sf::Drawable
	{
	public:
		std::vector<CH::Component*> Components;

		Entity(std::string name);
		~Entity();

		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);

		void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

		std::string GetId();
		std::string GetName();

	protected:
		std::string _uuid;
		std::string _name;

	};
}


