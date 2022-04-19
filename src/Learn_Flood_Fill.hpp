
#pragma once

#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct CoordinateIndex {
	std::size_t x;
	std::size_t y;
};

bool inbbx(const CoordinateIndex& size, const CoordinateIndex& pos) {
	if (pos.x < 0 || pos.y < 0)return false;
	else if (pos.x >= size.x || pos.y >= size.y) {
		return false;
	}
	return true;
}

/*
* find neighours of one node - its location is: pos
* 4 - connectivity: North, Sourth, West, East
* Need to check whether the neighour's value is equal to original value
* cuz in the traverse step the values of neighboring nodes may change
* 
* shape of grid:
*   0 1 2 3 4 5 6
* 0 * * * * * * *
* 1 * * * * * * *
* 2 * * * * * * *
* 3 * * * * * * *
* 4 * * * * * * *
* 5 * * * * * * *
* 6 * * * * * * *
*/
auto find_neighbours(
	const std::vector<std::vector<double>>& grid,
	CoordinateIndex pos,
	double original_value,
	double /* new_value */) {

	// get four neighbours - CCW order
	const std::vector<CoordinateIndex> possible_neighbours{
		{pos.x, pos.y - 1}, // North
		{pos.x + 1, pos.y}, // East
		{pos.x, pos.y + 1}, // Sourth
		{pos.x - 1, pos.y}  // West
	};




}


