#pragma once
#include <iostream>

template<std::size_t N, typename T>
class Vector {
private:
	T data[N];
public:

	// constructors ------------------------------------------------------
	Vector() {
		for (std::size_t i = 0; i != N; ++i)data[i] = T(0);
	}

	// explicit specifier -- avoid implicit conversions
	// for only one param, or n params but n-1 params have default values
	explicit Vector(const T& val) {
		for (std::size_t i = 0; i != N; ++i)data[i] = val;
	}

	std::size_t size() const{
		return N;
	}

	/* 
	conversion function
	return the memory address of the data
	convenient to pass the vector as a data pointer to functions
	e.g. 
	\code 

	void process_2d_vector(float* dptr) {}
	Vector<2, float> vec2d;
	process_2d_vector(vec2d); // conversion function to implicitly convert the data type

	\endcode
	*/
	operator T* () { return data; }

	// return the squared length of the vector
	T length_2() const {
		T res = T(0);
		for (std::size_t i = 0; i != N; ++i) {
			result += data[i] * data[i];
		}
		return result;
	}

	// return the length of the vector
	T length() const {
		return sqrt(length_2());
	}




};