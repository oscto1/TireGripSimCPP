#include <SFML/Graphics.hpp>
#include "main.h"
#include "Tire.h"
#include "TireState.h"
#include "TireRenderer.h"
#include <imgui.h>
#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui-SFML.h>

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


int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "Tire Grip Simulator");

	ImGui::SFML::Init(window);

	sf::Clock deltaClock;

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
		//ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::Begin("Test Window");
		ImGui::Text("ImGui is working!");
		ImGui::End();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && turnAngle > -35)
		{
			turnAngle -= 0.03f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && turnAngle < 35)
		{
			turnAngle += 0.03f;
		}

		state.calculateState({0.f, 0.f}, turnAngle, load, gripScale, speed);

		

		window.clear(sf::Color(30, 36, 40));
		
		TireRenderer::drawTireTop(window, state);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}

