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
	worldPosition.x -= (m_position.x - ((m_screenSize / 2) * m_scale));
	worldPosition.y -= (m_position.y - ((m_screenSize / 2) * m_scale));
	worldPosition /= m_scale;
	return worldPosition;
}

sf::Vector2f Camera::calcWorldPosition(sf::Vector2f screenPosition)
{
	screenPosition /= m_scale;
	screenPosition.x += (m_position.x - ((m_screenSize / 2) * m_scale));
	screenPosition.y += (m_position.y - ((m_screenSize / 2) * m_scale));
	return screenPosition;
}

float Camera::getScale()
{
	return m_scale;
}

void Camera::update(float deltaTime)
{
	if (m_eventHandler->keyPressed(sf::Keyboard::A))
	{
		m_position.x -= m_speed * m_scale * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::D))
	{
		m_position.x += m_speed * m_scale * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::S))
	{
		m_position.y += m_speed * m_scale * deltaTime;
	}

	if (m_eventHandler->keyPressed(sf::Keyboard::W))
	{
		m_position.y -= m_speed * m_scale * deltaTime;
	}

	if (m_eventHandler->mouseWheelScrolling(0))
	{
		m_scale *= 0.9;
	}

	if (m_eventHandler->mouseWheelScrolling(1))
	{
		m_scale /= 0.9;
	}
}

void Camera::setSpeed(float speed)
{
	m_speed = speed;
}

Camera::Camera()
{
	m_screenSize = 1000.0f;
	m_position = sf::Vector2f(m_screenSize / 2.0f, m_screenSize / 2.0f);
	m_scale = 1.0f;
	m_speed = 100.0f;
	m_eventHandler = EventHandler::getInstance();
}