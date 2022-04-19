
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



