#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "GameOfLife.h"
#include <iostream>

using namespace std;

int main() {
	int delay = 100;

	GameOfLife gameOfLife(true, 10);

	//SFML Version
	///*

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1600, 800), "Game Of Life", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asMilliseconds()>=delay)
		{
			window.clear(sf::Color(0,0,0));

			gameOfLife.draw(&window);
			gameOfLife.nextGeneration();

			clock.restart();
		}
		window.display();

	}

	//*/

	//Console version
	/*
	
	bool dalje;
	do {
		system("cls");

		cout << gameOfLife.toString();

		gameOfLife.nextGeneration();

		cout << "Dalje (1/0): ";
		cin >> dalje;

	} while (dalje);

	*/

	return 0;
}