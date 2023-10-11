#include "eventHandler.h"
#include "ImGuiHandler.h"
#include <iostream>

EventHandler* EventHandler::s_instance = nullptr;

EventHandler::EventHandler() 
{
	m_event = new sf::Event();
}

EventHandler* EventHandler::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new EventHandler();
	}

	return s_instance;
}

void EventHandler::handleEvents(sf::RenderWindow* window)
{
	ImGuiHandler* imHandler = ImGuiHandler::getInstance();

	memset(m_keyReleased, false, sizeof(bool) * 100);

	while (window->pollEvent(*m_event))
	{
		imHandler->pollEvents(window, m_event);

		if (m_event->type == sf::Event::Closed)
			window->close();

		if (m_event->type == sf::Event::KeyPressed)
		{
			m_keyPressed[m_event->key.scancode] = true;
		}

		if (m_event->type == sf::Event::KeyReleased)
		{
			m_keyReleased[m_event->key.scancode] = true;
			m_keyPressed[m_event->key.scancode] = false;
		}
	}
}

bool EventHandler::keyPressed(int key)
{
	return m_keyPressed[key];
}

bool EventHandler::keyReleased(int key)
{
	return m_keyReleased[key];
}
