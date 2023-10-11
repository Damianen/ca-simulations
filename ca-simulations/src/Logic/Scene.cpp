#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	m_updateTimer = 0.0f;

	m_map[0][1] = true;
	m_map[1][2] = true;
	m_map[2][0] = true;
	m_map[2][1] = true;
	m_map[2][2] = true;
}

void Scene::update(float deltaTime)
{
	if (m_updateTimer > 0.1f)
	{
		m_updateTimer = 0.0f;
		calculateNextFrame();
	}

	m_updateTimer += deltaTime;
}

void Scene::calculateNextFrame()
{
	for (int x = 0; x < s_mapSize; x++)
		for (int y = 0; y < s_mapSize; y++)
		{
			m_tempMap[x][y] = checkCell(sf::Vector2i(x, y));
		}

	memcpy(m_map, m_tempMap, sizeof(bool) * s_mapSize * s_mapSize);
}

bool Scene::checkCell(sf::Vector2i mapCoords)
{
	int aliveNeigbouringCells = 0;

	for (int x = mapCoords.x - 1; x < mapCoords.x + 2; x++)
		for (int y = mapCoords.y - 1; y < mapCoords.y + 2; y++)
		{
			if (sf::Vector2i(x, y) == mapCoords || x >= s_mapSize || y >= s_mapSize || y < 0 || x < 0) 
			{ 
				continue; 
			}

			if (m_map[x][y])
			{
				aliveNeigbouringCells++;
			}
		}

	if (m_map[mapCoords.x][mapCoords.y])
	{
		if (aliveNeigbouringCells >= 2 && aliveNeigbouringCells <= 3)
		{
			return true;
		}
	}
	else 
	{
		if (aliveNeigbouringCells == 3)
		{
			return true;
		}
	}

	return false;
}
