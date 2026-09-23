#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
class Array
{
	private:
		T* _data;
		unsigned int _size;


	public:
		Array();
		Array(unsigned int n);
		Array(Array const& other);
		Array& operator=(Array const& other);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"

#endif