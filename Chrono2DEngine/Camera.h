#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace CH {
	class Camera : public CH::Component
	{
	public:
		sf::View View;

		Camera();
		~Camera();

		virtual void SetFollow(Entity* entityToFollow);
		virtual void SetZoom(float newZoom);
		virtual void SetSize(float newSizeX, float newSizeY);

		virtual void SetViewport(sf::FloatRect newViewport);

		virtual void SetRotation(float newRotation);
		virtual void Rotate(float rotateAmount);

		void LateUpdate(float deltaTime) override;

	protected:
		bool _cameraFollow;
		Entity* _entityToFollow;
	private:
	};
}

