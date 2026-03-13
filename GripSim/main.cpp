#include <SFML/Graphics.hpp>
#include "Tire.h"
#include "TireState.h"
#include "TireRenderer.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include "Utils.h"
#include <iostream>

void handleResize(sf::RenderWindow& window, unsigned width, unsigned height);
void drawUI(float &speed, float &load, Utils::UnitSystems &currentUnit);

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	ImGui::SFML::Init(window);

	sf::Clock deltaClock;

	Utils::UnitSystems currentUnit = Utils::UnitSystems::METRIC;

	Tire tire(0.32f, 0.255f, 210000.f, 0.8f, {(float)window.getSize().x / 2,  (float)window.getSize().y / 2});
	TireState state(tire);

	float load = 7000.f;
	float turnAngle = 0.f;
	float speed = 100.f;
	float gripScale = 10;

	auto size = window.getSize();
	handleResize(window, size.x, size.y);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);

			if (event->is<sf::Event::Closed>())
				window.close();

			if (const auto* resized = event->getIf<sf::Event::Resized>())
			{
				handleResize(window, resized->size.x, resized->size.y);
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && turnAngle > -35)
		{
			turnAngle -= 0.03f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && turnAngle < 35)
		{
			turnAngle += 0.03f;
		}

		state.calculateState({0.f, 0.f}, turnAngle, load, gripScale, speed);

		drawUI(speed, load, currentUnit);

		window.clear(sf::Color(30, 36, 40));
		
		TireRenderer::drawTireTop(window, state);
		ImGui::SFML::Render(window);
		window.display();

		if (currentUnit == Utils::UnitSystems::METRIC)
		{
			std::cout << "Metric" << std::endl;
		}	

		if (currentUnit == Utils::UnitSystems::IMPERIAL)
		{
			std::cout << "Imperial" << std::endl;
		}
	}

	ImGui::SFML::Shutdown();
}


void handleResize(sf::RenderWindow& window, unsigned width, unsigned height)
{
	float windowRatio = (float)width / height;
	float viewRatio = 1.0f; // 800 / 800

	float sizeX = 1.0f;
	float sizeY = 1.0f;
	float posX = 0.f;
	float posY = 0.f;

	bool horizontalSpacing = windowRatio > viewRatio;

	if (horizontalSpacing)
	{
		sizeX = viewRatio / windowRatio;
		posX = (1.f - sizeX) / 2.f;
	}
	else
	{
		sizeY = windowRatio / viewRatio;
		posY = (1.f - sizeY) / 2.f;
	}

	sf::View view(sf::FloatRect({ 0.f, 0.f }, { 800.f, 800.f }));
	view.setViewport(sf::FloatRect({ posX, posY }, { sizeX, sizeY }));

	window.setView(view);
}

void drawUI(float &speed, float &load, Utils::UnitSystems &currentUnit)
{
	ImGui::Begin("Controls");
	ImGui::SliderFloat("Speed (m/s)", &speed, 0.f, 80.f);
	ImGui::SliderFloat("Load (N)", &load, 4000.f, 9000.f);
	ImGui::End();

	ImGui::Begin("Unit System");
	if (ImGui::RadioButton("Metric", currentUnit == Utils::UnitSystems::METRIC))
	{
		currentUnit = Utils::UnitSystems::METRIC;
	}

	if (ImGui::RadioButton("Imperial", currentUnit == Utils::UnitSystems::IMPERIAL))
	{
		currentUnit = Utils::UnitSystems::IMPERIAL;
	}
	ImGui::End();
}