#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class GameOfLife
{
private:
	static const unsigned int COLUMNS = 160;
	static const unsigned int ROWS = 80;

	sf::Color populated_cell_color = sf::Color(167, 209, 41);
	sf::Color cell_3D_effect_color = sf::Color(97, 111, 57);
	sf::Color outline_color = sf::Color(62, 67, 46);

	bool infinite_grid;
	bool generation[ROWS][COLUMNS];
	bool next_generation[ROWS][COLUMNS];
	bool randomBool(int true_percentage);
	bool cellPopulated(int i, int j);
	int countNeighbours(int i, int j);

public:
	GameOfLife();
	GameOfLife(bool infinite_grid);
	GameOfLife(bool infinite_grid, int cell_alive_probability);
	GameOfLife(bool infinite_grid, int cell_alive_probability, int seed);
	void nextGeneration();
	void draw(sf::RenderWindow* window);
	string toString();
	string toString(char populated_cell, char unpopulated_cell);
};