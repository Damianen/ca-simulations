#pragma once
#include <SFML/Graphics.hpp>

class ImGuiHandler
{
public:
	static ImGuiHandler* getInstance();
	static ImGuiHandler* createInstance(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow* window, sf::Event* event);
	void update(sf::Time deltaTime, sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
private:
	ImGuiHandler(sf::RenderWindow* window);
	static ImGuiHandler* s_instace;
};

