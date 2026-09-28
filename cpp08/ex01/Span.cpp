#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(Span const& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	
	if (_numbers.size() >= _maxSize)
		throw (FullException());
	else
		_numbers.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	else
	{
		std::vector<int> copie = _numbers;

		std::sort(copie.begin(), copie.end());

		long shortest = static_cast<long>(copie[1]) - copie[0];
		for (size_t i = 0; i + 1 < copie.size(); i++)
		{
			long diff = static_cast<long>(copie[i + 1]) - copie[i];
			if (shortest > diff)
				shortest = diff;
		}
		return (static_cast<unsigned int>(shortest));
	}
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	else
	{
		std::vector<int> copie = _numbers;
		std::sort(copie.begin(), copie.end());

		long longest = static_cast<long>(copie[copie.size() - 1]) - copie[0];
		
		return (static_cast<unsigned int>(longest));
	}
}

const char* Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("There are not enough numbers");
}
