
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

	CoordinateIndex(std::size_t px, std::size_t py) {
		x = px;
		y = py;
	}
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
* Need to check whether the neighour's value is equal to original value -- fill boundary
* 
* shape of grid:
*   0 1 2 3 4 5 6 -- x
* 0 * * * * * * *
* 1 * * * * * * *
* 2 * * * * * * *
* 3 * * * * * * *
* 4 * * * * * * *
* 5 * * * * * * *
* 6 * * * * * * *
* |
* y
*/
auto find_neighbors(
	const std::vector<std::vector<double>>& grid,
	CoordinateIndex pos,
	double original_value,
	double /* new_value */) {

	// get four neighbours - CCW order
	const std::vector<CoordinateIndex> possible_neighbors{
		{pos.x, pos.y - 1}, // North
		{pos.x + 1, pos.y}, // East
		{pos.x, pos.y + 1}, // Sourth
		{pos.x - 1, pos.y}  // West
	};

	std::vector<CoordinateIndex> neighbors; // store the neighbors

	for (auto const& possible_neighbor : possible_neighbors) {
		const auto size = CoordinateIndex(grid[0].size(), grid.size());
		const auto x = possible_neighbor.x;
		const auto y = possible_neighbor.y;
		if (inbbx(size, possible_neighbor) && grid[x][y] == original_value) { // check the boundary
			neighbors.push_back(possible_neighbor);
		}
	}

	return neighbors;


}

/*
* DFS: use stack to traverse
*/
void DFS_fill(
	std::vector<std::vector<double>>& grid,
	CoordinateIndex pos,
	double original_value,
	double new_value) {

	if (new_value == original_value)return;

	const auto size = CoordinateIndex(grid[0].size(), grid.size());
	assert(pos.x < size.x && pos.y < size.y);

	std::stack<CoordinateIndex> s;
	s.push(pos); // initialize

	while (!s.empty()) {
		const auto& current_pos = s.top();
		s.pop();

		const auto& x = current_pos.x;
		const auto& y = current_pos.y;

		if (grid[x][y] == original_value) {
			grid[x][y] = new_value; // change the attribute
			const auto neighbors = find_neighbors(grid, current_pos, original_value, new_value);
			for (const auto& neighbor : neighbors) {
				s.push(neighbor);
			}
		}
	}
	
}


