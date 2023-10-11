#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene();
	void update(float deltaTime);
	void pause();

	const static int s_mapSize = 100;
	bool m_map[s_mapSize][s_mapSize]{ false };

private:
	void calculateNextFrame();
	bool checkCell(sf::Vector2i mapCoords);
	bool m_tempMap[s_mapSize][s_mapSize]{ false };

	float m_updateTimer;
	bool m_paused;
};

