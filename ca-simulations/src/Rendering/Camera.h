#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class EventHandler;

class Camera
{
public:
	static Camera* getInstance();
	sf::Vector2f calcScreenPosition(sf::Vector2f worldPosition);
	sf::Vector2f calcWorldPosition(sf::Vector2f screenPosition);
	float getScale();
	void update(float deltaTime);
	void setSpeed(float speed);

private:
	Camera();

	static Camera* s_Instance;
	sf::Vector2f m_position;
	float m_scale;
	float m_speed;
	float m_screenSize;
	EventHandler* m_eventHandler;
};

