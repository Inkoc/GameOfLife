# Game of Life

This project is an implementation of the Game of Life, a cellular automaton devised by the British mathematician John Horton Conway in 1970. The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

## Rules of the Game

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead (or populated and unpopulated, respectively). Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent.

At each step in time, the following transitions occur:
- Any live cell with fewer than two live neighbors dies, as if by underpopulation.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by overpopulation.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

## Code Overview

The code is written in C++ and utilizes the SFML library for the graphical user interface.

### GameOfLife Class

The `GameOfLife` class represents the game grid. The class constructor accepts the following parameters:

- `bool infinite_grid`: Determines if the grid is infinite. Defaults to false. If set to true, the grid behaves as a toroidal array (like a game of Pac-Man), where cells on the edge of the grid consider cells on the opposite edge as their neighbors. This creates an effect where the grid appears to “wrap around” to the other side.
- `int cell_alive_probability`: The percentage chance that a cell will be populated in the first generation. Defaults to `25`.
- `int seed`: The seed used to generate the first grid. If not provided, a random seed is used.

#### Methods

The `GameOfLife` class includes the following methods:

- `nextGeneration()`: Calculates the next state of cells based on the current state.
- `draw(sf::RenderWindow* window)`: Draws the current state of the game grid to the provided SFML window.
- `toString(char populated_cell = '*', char unpopulated_cell = '-')`: Returns a string representation of the current game grid. The characters representing populated and unpopulated cells can be provided as arguments. If not provided, populated cells are represented by `*` and unpopulated cells by `-`.
