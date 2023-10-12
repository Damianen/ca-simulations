#pragma once
#include <SFML/Graphics.hpp>

class EventHandler
{
public:
	static EventHandler* getInstance();
	void handleEvents(sf::RenderWindow* window);;
	bool keyPressed(int key);
	bool keyReleased(int key);
	bool mousePressed(int mouseKey);
	bool mouseWheelScrolling(int mouseDirection);
	sf::Vector2i getMousePosition();

private:
	EventHandler();

	static EventHandler* s_instance;
	sf::Event* m_event;

	bool m_keyPressed[100] = { false };
	bool m_keyReleased[100] = { false };
	bool m_mousePressed[3] = { false };
	bool m_mouseWheelScroll[2] = {false};
	sf::Vector2i m_mousePosition;
};

