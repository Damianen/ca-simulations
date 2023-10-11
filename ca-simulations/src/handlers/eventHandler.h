#pragma once
#include <SFML/Graphics.hpp>

class EventHandler
{
public:
	static EventHandler* getInstance();
	void handleEvents(sf::RenderWindow* window);;
	bool keyPressed(int key);
	bool keyReleased(int key);

private:
	EventHandler();

	static EventHandler* s_instance;
	sf::Event* m_event;

	bool m_keyPressed[100] = { false };
	bool m_keyReleased[100] = { false };
};

