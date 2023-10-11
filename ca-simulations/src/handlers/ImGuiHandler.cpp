#include "ImGuiHandler.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "Logic/Scene.h"

ImGuiHandler* ImGuiHandler::s_instace = nullptr;

ImGuiHandler::ImGuiHandler(sf::RenderWindow* window)
{
	ImGui::SFML::Init(*window);
}

ImGuiHandler* ImGuiHandler::getInstance()
{
	if (s_instace != nullptr)
	{
		return s_instace;
	}
	
	return nullptr;
}

ImGuiHandler* ImGuiHandler::createInstance(sf::RenderWindow* window)
{
	if (s_instace != nullptr)
	{
		return s_instace;
	}

	return new ImGuiHandler(window);
}

void ImGuiHandler::pollEvents(sf::RenderWindow* window, sf::Event* event)
{
	ImGui::SFML::ProcessEvent(*window, *event);
}

void ImGuiHandler::update(sf::Time deltaTime, sf::RenderWindow* window, Scene* scene)
{
	ImGui::SFML::Update(*window, deltaTime);

	ImGui::Begin("Toolbox!");
	if (ImGui::Button("Pause")) { scene->pause(); }
	ImGui::End();
}

void ImGuiHandler::render(sf::RenderWindow* window)
{
	ImGui::SFML::Render(*window);
}
