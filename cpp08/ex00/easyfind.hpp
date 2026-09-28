#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <class T>
typename T::iterator easyfind(T& cont, int value)
{
	typename T::iterator it = cont.begin();
	while (it != cont.end())
	{
		if (*it == value)
			return (it);
		++it;
	}
	return (cont.end());
}

#endif