#include "Renderer.h"
#include "Logic/Scene.h"
#include "Camera.h"

Renderer::Renderer()
{}

void Renderer::render(sf::RenderWindow* window, Scene* scene)
{
	Camera* cam = Camera::getInstance();

	sf::RectangleShape rect(sf::Vector2f(10.0f, 10.0f));
	rect.setFillColor(sf::Color::White);

	for (int x = 0; x < scene->s_mapSize; x++)
		for (int y = 0; y < scene->s_mapSize; y++)
		{
			if (scene->m_map[x][y]) 
			{
				rect.setPosition(cam->calcScreenPosition(sf::Vector2f(x, y)));
				window->draw(rect);
			}
		}
}
