#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <class T, class F>
void iter (T* arr, const size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

#endif