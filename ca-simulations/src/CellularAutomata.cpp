#include "CellularAutomata.h"
#include "Rendering/Renderer.h"
#include "Logic/Scene.h"
#include <chrono>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Handlers/ImGuiHandler.h"
#include "handlers/eventHandler.h"
#include "Rendering/Camera.h"
#include<iostream>

CellularAutomata::CellularAutomata()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Cellular Automata!");
    m_renderer = new Renderer();
    m_scene = new Scene();
    m_imHandler = ImGuiHandler::createInstance(m_window);
    m_Camera = Camera::getInstance();
    m_eventHandler = EventHandler::getInstance();
}

void CellularAutomata::mainLoop()
{
    sf::Clock deltaClock;

    std::chrono::steady_clock::time_point lastUpdate;
    float deltaTime = 0.0f;

    while (m_window->isOpen())
    {
        m_eventHandler->handleEvents(m_window);

        update(deltaClock.getElapsedTime(), deltaTime);
        
        Render();

        deltaClock.restart();

        auto now = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
        lastUpdate = now;
    }

    ImGui::SFML::Shutdown();
}

void CellularAutomata::update(sf::Time time, float deltaTime)
{
    m_scene->update(deltaTime);

    m_Camera->update(deltaTime);

    m_imHandler->update(time, m_window);
}

void CellularAutomata::Render()
{

    m_window->clear(sf::Color::Black);

    m_renderer->render(m_window, m_scene);

    m_imHandler->render(m_window);

    m_window->display();
}

