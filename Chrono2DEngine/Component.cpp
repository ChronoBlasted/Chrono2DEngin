#include "Component.h"
#include "Application.h"

CH::Component::Component()
{
	_uuid = Application::GetInstance()->GenerateID();
}

CH::Component::~Component()
{
}

std::string CH::Component::GetId()
{
	return _uuid;
}

void CH::Component::Awake()
{
}

void CH::Component::Start()
{
}

void CH::Component::Update(float deltaTime)
{

}

void CH::Component::LateUpdate(float deltaTime)
{
}
