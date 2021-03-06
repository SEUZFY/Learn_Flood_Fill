#pragma once
#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

template<std::size_t N, typename T>
class Vector {
private:
	T data[N];
public:

	// constructors ------------------------------------------------------------------
	Vector() {
		for (std::size_t i = 0; i != N; ++i)data[i] = T{}; // zero - initialization, same as T(0)
	}

	// explicit specifier -- avoid implicit conversions
	// for only one param, or n params but n-1 params have default values
	explicit Vector(const T& val) {
		for (std::size_t i = 0; i != N; ++i)data[i] = val;
	}
	// constructors ------------------------------------------------------------------


	/*
	* return the memory address of the vector
	* useful to access the data[N]
	*/
	T* Getdata() { return data; }

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
		T res = T{}; // zero - initialization, same as T(0)
		for (std::size_t i = 0; i != N; ++i) {
			result += data[i] * data[i];
		}
		return result;
	}

	// return the length of the vector
	T length() const {
		return sqrt(length_2());
	}

	// return the squared distance of another vector
	typedef Vector<N, T> ThisVector;
	T distance_2(const ThisVector& other) {
		T result = T{};
		for (std::size_t i = 0; i != N; ++i) {
			T val = other.data[i] - data[i]; // access the private members inside the class
			result += val * val;
		}
		return result;
	}

	// return the distance of another vector 
	T distance(const ThisVector& other) {
		return sqrt(distance_2(other));
	}


	// Basic operations [+-*/] ------------------------------------------------------------------

	/*
	* function: sum two vectors
	* @return: sum vector
	* It will copy the current vector and then perform the sum operation
	* in such manner the original vector can be preserved
	* e.g.
	* \code
	* 
	* Vector<2, float> vec_a;
    * Vector<2, float> vec_b;
	* ... // assign different values to vec_a and vec_b
	* auto sum_vec = vec_a + vec_b;
	* sum_vec.print();
    * vec_a.print(); // keep the original value
	* 
	* \endcode
	*/
	ThisVector operator+ (const ThisVector& vec) const{
		ThisVector result(*this); // result is a copy of current vector: *this
		for (std::size_t i = 0; i != N; ++i) {
			result.data[i] += vec.data[i];
		}
		return result;
	}

	// operator-
	ThisVector operator- (const ThisVector& vec) const{
		ThisVector result(*this); // result is a copy of current vector: *this
		for (std::size_t i = 0; i != N; ++i) {
			result.data[i] -= vec.data[i];
		}
		return result;
	}

	// operator*, the type need to be the same to avoid the implicit conversion
	ThisVector operator* (T val) const {
		ThisVector result(*this); // result is a copy of current vector: *this
		for (std::size_t i = 0; i != N; ++i) {
			result.data[i] *= val;
		}
		return result;
	}

	// operator/, the type need to be the same to avoid the implicit conversion
	ThisVector operator/ (T val) const {
		assert(val != T{});
		ThisVector result(*this); // result is a copy of current vector: *this
		for (std::size_t i = 0; i != N; ++i) {
			result.data[i] /= val;
		}
		return result;
	}
	// Basic operations [+-*/] ------------------------------------------------------------------


	// print itself
	void print() {
		for (std::size_t i = 0; i != N; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << '\n';
	}

};