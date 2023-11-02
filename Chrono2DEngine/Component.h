#pragma once
#include <string>

namespace CH {
	class Component
	{
	public:
		Component();
		~Component();

		virtual void Awake();
		virtual void Start();
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);

		std::string GetId();

	protected:
		std::string _uuid;

	};

}