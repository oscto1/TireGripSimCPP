#include <SFML/Graphics.hpp>
#include "Tire.h"
#include "TireState.h"
#include "TireRenderer.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include "Utils.h"
#include <iostream>

void handleResize(sf::RenderWindow& window, unsigned width, unsigned height);
void drawUI(float &speed, float &load, TireState& tireState, Utils::UnitSystems &currentUnit);

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	ImGui::SFML::Init(window);

	sf::Clock deltaClock;

	Utils::UnitSystems currentUnit = Utils::UnitSystems::METRIC;

	//Tire data
	//float radius = 0.32f;
	//float width = 0.255f;
	//float pressure = 210000.f;
	TireData tireData;
	tireData.radius = 0.32f;
	tireData.width = 0.255f;
	tireData.pressure = 210000.f;
	tireData.baseGrip = 0.8f;

	Tire tire(tireData, {(float)window.getSize().x / 2,  (float)window.getSize().y / 2});

	

	//Controls
	TireState state(tire);
	float load = 7000.f;
	float turnAngle = 0.f;
	float speed = 5.f;
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

		drawUI(speed, load, state, currentUnit);

		window.clear(sf::Color(30, 36, 40));
		
		TireRenderer::drawTireTop(window, state);
		ImGui::SFML::Render(window);
		window.display();
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

void drawUI(float &speed, float &load, TireState &tireState, Utils::UnitSystems &currentUnit)
{
	ImGui::Begin("Tire");
	ImGui::PushItemWidth(110.0f);
	if (ImGui::SliderFloat("Width", &tireState.m_tire.data.width, 0.155f, 0.305f))
	{
		tireState.m_tire.topShape.updateTireShape({ tireState.m_tire.data.width * Utils::PIXELS_PER_METER, tireState.m_tire.data.radius * Utils::PIXELS_PER_METER * 2 });
	}

	if(ImGui::SliderFloat("Radius", &tireState.m_tire.data.radius, 0.28f, 0.4f))
	{
		tireState.m_tire.topShape.updateTireShape({ tireState.m_tire.data.width * Utils::PIXELS_PER_METER, tireState.m_tire.data.radius * Utils::PIXELS_PER_METER * 2 });
	}
	ImGui::SliderFloat("Pressure", &tireState.m_tire.data.pressure, 100000.f, 260000.f);

	ImGui::PopItemWidth();
	ImGui::End();

	ImGui::Begin("Controls");
	ImGui::PushItemWidth(110.0f);

	if (currentUnit == Utils::UnitSystems::METRIC)
	{
		float speedKmH = speed * 3.6;
		if (ImGui::SliderFloat("Speed (Km/h)", &speedKmH, 0.f, 306.f))
		{
			speed = speedKmH / 3.6;
		};

		ImGui::SliderFloat("Load (N)", &load, 4000.f, 9000.f);
	}
	else
	{
		float speedMH = speed * 2.23694f;
		if (ImGui::SliderFloat("Speed (Mph)", &speedMH, 0.f, 190.14f))
		{
			speed = speedMH / 2.23694f;
		};

		float loadLbF = load * 0.2248089f;
		if (ImGui::SliderFloat("Load (Lbf)", &loadLbF, 899.23f, 2023.28f))
		{
			load = loadLbF / 0.2248089f;
		}
	}

	ImGui::PopItemWidth();
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