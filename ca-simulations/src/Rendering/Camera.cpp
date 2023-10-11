#include "Camera.h"
#include "handlers/eventHandler.h"

Camera* Camera::s_Instance = nullptr;

Camera* Camera::getInstance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new Camera();
	}

	return s_Instance;
}

sf::Vector2f Camera::calcScreenPosition(sf::Vector2f worldPosition)
{
	return (worldPosition - m_position) * 10.0f;
}

sf::Vector2f Camera::calcWorldPosition(sf::Vector2f screenPosition)
{
	return (screenPosition + m_position) / 10.0f;
}

void Camera::update(float deltaTime)
{
	if (m_eventHandler->keyPressed(sf::Keyboard::A))
	{
		m_position.x -= m_speed * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::D))
	{
		m_position.x += m_speed * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::S))
	{
		m_position.y += m_speed * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::W))
	{
		m_position.y -= m_speed * deltaTime;
	}
}

Camera::Camera()
{
	m_position = sf::Vector2f(0.0f, 0.0f);
	m_zoom = 1.0f;
	m_speed = 30.0f;
	m_eventHandler = EventHandler::getInstance();
}