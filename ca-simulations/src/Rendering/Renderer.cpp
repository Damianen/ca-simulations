#include "Renderer.h"
#include "Logic/Scene.h"
#include "Camera.h"

Renderer::Renderer()
{}

void Renderer::render(sf::RenderWindow* window, Scene* scene)
{
	Camera* cam = Camera::getInstance();

	sf::RectangleShape rect(sf::Vector2f(1.0f / cam->getScale(), 1.0f / cam->getScale()));
	rect.setFillColor(sf::Color::White);

	for (int x = 0; x < scene->s_mapSize; x++)
	{
		sf::Vector2f screenPos = cam->calcScreenPosition(sf::Vector2f(x, 0.0f));
		
		if (screenPos.x < 0 || screenPos.x > Scene::s_mapSize) continue;
		
		for (int y = 0; y < scene->s_mapSize; y++)
		{
			if (!scene->m_map[x][y]) continue;

			sf::Vector2f screenPos = cam->calcScreenPosition(sf::Vector2f(0.0f, y));

			if (screenPos.y < 0 || screenPos.y > Scene::s_mapSize) continue;

			rect.setPosition(cam->calcScreenPosition(sf::Vector2f(x, y)));
			window->draw(rect);
		}
	}
}
