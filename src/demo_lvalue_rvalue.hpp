#pragma once
#include <iostream>

class Holder
{
public:

    Holder(int size)         // Constructor
    {
        m_data = new int[size];
        m_size = size;
        std::cout << "constructor called" << '\n';
    }

    // Rule of three --------------------------------------------------------------------------
    Holder(const Holder& other) { // copy constructor
        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size; // access private members inside the class
        std::cout << "copy constructor called" << '\n';
    }

    /*
    * const specifier: to avoid errorneous syntax
    * e.g.
    * \code
    * 
    * Holder h1(100);
    * Holder h2(h1);
    * (h1 = h2).print(); // avoid this confusing syntex
    * 
    * \endcode
    */
    const Holder& operator=(const Holder& other) { // assignment operator
        if (this == &other)return *this;
        delete[] m_data;

        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size; // access private members inside the class

        std::cout << "assignment operator called" << '\n';
        return *this;
    }

    ~Holder()                // Destructor
    {
        delete[] m_data;
    }
    // Rule of three --------------------------------------------------------------------------


    // Rule of five ----------------------------------------------------------------------------
    Holder(Holder&& other)     // <-- rvalue reference in input
    {
        m_data = other.m_data;   // (1)
        m_size = other.m_size;
        other.m_data = nullptr;  // (2)
        other.m_size = 0;
        std::cout << "move constructor called" << '\n';
    }

    Holder& operator=(Holder&& other)     // <-- rvalue reference in input  
    {
        if (this == &other) return *this;

        delete[] m_data;         

        m_data = other.m_data;  // move resources
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_size = 0;

        std::cout << "move assignment called" << '\n';
        return *this;
    }
    // Rule of five ----------------------------------------------------------------------------

    void print() {
        std::cout << "memory address: " << m_data << '\n';
        std::cout << "size: " << m_size << '\n';
    }

private:

    int* m_data;
    int  m_size;
};
