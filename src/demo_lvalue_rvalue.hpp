#pragma once
#include <iostream>

class Holder
{
public:

    Holder(int size)         // Constructor
    {
        m_data = new int[size];
        m_size = size;
        std::cout << "normal constructor called" << '\n';
    }

    Holder(const Holder& other) { // copy constructor
        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size; // access private members inside the class
        std::cout << "copy constructor called" << '\n';
    }

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

    void print() {
        std::cout << "memory address: " << m_data << '\n';
        std::cout << "size: " << m_size << '\n';
    }

private:

    int* m_data;
    int  m_size;
};
