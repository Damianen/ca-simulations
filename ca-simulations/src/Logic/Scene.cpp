#include "Scene.h"
#include <algorithm>
#include <execution>


Scene::Scene()
{
	m_updateTimer = 0.0f;
	m_paused = false;

	for (int i = 0; i < s_mapSize; i++)
	{
		m_yPositions.push_back(i);

		for (int j = 0; j < s_mapSize; j++)
		{
			if (rand() % 2)
			{
				m_map[i][j] = true;
			}
		}
	}
}

void Scene::update(float deltaTime)
{
	if (m_updateTimer > 0.1f)
	{
		m_updateTimer = 0.0f;
		calculateNextFrame();
	}

	if (!m_paused)
	{
		m_updateTimer += deltaTime;
	}
}

void Scene::pause()
{
	if (m_paused)
	{
		m_paused = false;
		return;
	}

	m_paused = true;
}

void Scene::calculateNextFrame()
{
	std::for_each(std::execution::par_unseq, std::begin(m_yPositions), std::end(m_yPositions), [&](int x)
		{
			for (int y = 0; y < s_mapSize; y++)
			{
				m_tempMap[x][y] = checkCell(sf::Vector2i(x, y));
			}
		});

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
