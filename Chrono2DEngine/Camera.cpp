#include "Camera.h"
#include "Application.h"

CH::Camera::Camera()
{
	_cameraFollow = false;
	View = sf::View(Application::GetInstance()->Window.getDefaultView());
}

CH::Camera::~Camera()
{
}

void CH::Camera::SetFollow(Entity* entityToFollow)
{
	_entityToFollow = entityToFollow;
	_cameraFollow = true;
}

void CH::Camera::SetZoom(float zoom)
{
	View.zoom(zoom);
}

void CH::Camera::SetSize(float sizeX, float sizeY)
{
	View.setSize(sizeX, sizeY);
}

void CH::Camera::SetViewport(sf::FloatRect newViewport)
{
	View.setViewport(newViewport);
}

void CH::Camera::SetRotation(float newRotation)
{
	View.setRotation(newRotation);
}

void CH::Camera::Rotate(float rotateAmount)
{
	View.rotate(rotateAmount);
}

void CH::Camera::LateUpdate(float deltaTime)
{
	if (_cameraFollow) {
		View.setCenter(_entityToFollow->getPosition());
		Application::GetInstance()->SetView(View);
	}
}