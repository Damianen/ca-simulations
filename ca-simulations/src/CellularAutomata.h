#pragma once
#include <SFML/Graphics.hpp>

class Renderer;
class Scene;
class ImGuiHandler;
class Camera;
class EventHandler;

class CellularAutomata
{
public:
	CellularAutomata();
	void mainLoop();

private:
	void update(sf::Time time, float deltaTime);
	void Render();

	sf::RenderWindow* m_window;
	Renderer* m_renderer;
	Scene* m_scene;
	ImGuiHandler* m_imHandler;
	Camera* m_Camera;
	EventHandler* m_eventHandler;
};

