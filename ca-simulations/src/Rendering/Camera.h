#pragma once
#include <SFML/Graphics.hpp>

class EventHandler;

class Camera
{
public:
	static Camera* getInstance();
	sf::Vector2f calcScreenPosition(sf::Vector2f worldPosition);
	sf::Vector2f calcWorldPosition(sf::Vector2f screenPosition);
	void update(float deltaTime);

private:
	Camera();

	static Camera* s_Instance;
	sf::Vector2f m_position;
	float m_zoom;
	float m_speed;
	EventHandler* m_eventHandler;
};

