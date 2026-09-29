#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(MutantStack const& other);
		MutantStack& operator=(MutantStack const& other);
		~MutantStack();

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif