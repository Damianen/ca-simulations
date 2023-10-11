#pragma once
#include <SFML/Graphics.hpp>

class Scene;

class Renderer
{
public:
	Renderer();
	void render(sf::RenderWindow* window, Scene* scene);
};

