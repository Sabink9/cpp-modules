#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

int main()
{
	std::srand(std::time(NULL));

	// Exemple du sujet : 2 puis 14
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Span plein
	try 
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// Pas assez de nombres
	Span empty(5);
	try 
	{
		empty.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// Valeurs extrêmes : 4294967295
	Span ext(2);
	ext.addNumber(INT_MIN);
	ext.addNumber(INT_MAX);
	std::cout << ext.longestSpan() << std::endl;

	// 10 000 nombres avec addRange
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(std::rand());
	Span big(10000);
	big.addRange(v.begin(), v.end());
	std::cout << "shortest : " << big.shortestSpan() << " longest : " << big.longestSpan() << std::endl;

	return (0);
}