#include "GameOfLife.h"
#include <ctime>
#include <sstream>

using namespace std;

bool GameOfLife::randomBool(int true_percentage)
{
	return rand() % 100 + 1 <= true_percentage;
}

bool GameOfLife::cellPopulated(int i, int j)
{
	return generation[i][j];
}

int GameOfLife::countNeighbours(int i, int j)
{
	int neighbour_count = 0;

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) continue;

			int ni, nj;
			if (infinite_grid) {
				ni = (i + x + ROWS) % ROWS;
				nj = (j + y + COLUMNS) % COLUMNS;
			}
			else {
				ni = i + x;
				nj = j + y;
			}

			if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLUMNS && cellPopulated(ni, nj)) {
				neighbour_count++;
			}
		}
	}

	return neighbour_count;
}

GameOfLife::GameOfLife() : GameOfLife(false, 25, time(nullptr)) {}

GameOfLife::GameOfLife(bool infinite_grid) : GameOfLife(infinite_grid, 25, time(nullptr)) {}

GameOfLife::GameOfLife(bool infinite_grid,  int cell_alive_probability) : GameOfLife(infinite_grid, cell_alive_probability, time(nullptr)) {}

GameOfLife::GameOfLife(bool infinite_grid,  int cell_alive_probability, int seed)
{
	this->infinite_grid = infinite_grid;

	srand(seed);

	if (cell_alive_probability <= 0)
	{
		cell_alive_probability = 0;
	}
	else if (cell_alive_probability > 100)
	{
		cell_alive_probability = 100;
	}

	for (auto& row : generation)
	{
		for (auto& cell : row)
		{
			cell = randomBool(cell_alive_probability);
		}
	}
}

void GameOfLife::nextGeneration()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			if (cellPopulated(i, j) && (countNeighbours(i, j) == 2 || countNeighbours(i, j) == 3))
			{
				next_generation[i][j] = true;
			}

			else if (!cellPopulated(i, j) && countNeighbours(i, j) == 3)
			{
				next_generation[i][j] = true;
			}

			else {
				next_generation[i][j] = false;
			}
		}
	}

	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			generation[i][j] = next_generation[i][j];
		}
	}
}

void GameOfLife::draw(sf::RenderWindow* window)
{
	float x, y;

	x = (float)window->getView().getSize().x / COLUMNS;
	y = (float)window->getView().getSize().y / ROWS;

	sf::RectangleShape cell;
	cell.setSize(sf::Vector2f(x, y));
	cell.setFillColor(sf::Color(0, 255, 34));
	cell.setOutlineColor(outline_color);
	cell.setOutlineThickness(x/30);
	cell.setFillColor(populated_cell_color);

	sf::RectangleShape cell3DEffect;
	cell3DEffect.setSize(sf::Vector2f(x * 1.3, y * 1.3));
	cell3DEffect.setFillColor(cell_3D_effect_color);
	cell3DEffect.setOutlineColor(outline_color);
	cell3DEffect.setOutlineThickness(x/30);

	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++) 
		{

			if (cellPopulated(i, j))
			{
				cell.setPosition(j * x, i * y);

				cell3DEffect.setPosition(j * x, i * y);
				window->draw(cell3DEffect);
				window->draw(cell);

			}

		}
	}
}

string GameOfLife::toString()
{
	return toString('*', '-');
}

string GameOfLife::toString(char populated_cell, char unpopulated_cell)
{
	stringstream ss;
	for (auto& row : generation)
	{
		for (auto& cell : row)
		{
			if (cell) {
				ss << populated_cell;
			}
			else
			{
				ss << unpopulated_cell;
			}
		}
		ss << endl;
	}
	return ss.str();
}

