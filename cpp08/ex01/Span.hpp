#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(Span const& other);
		Span& operator=(Span const& other);
		~Span();

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		
		class FullException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class NotEnoughNumbersException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	unsigned int count = std::distance(begin, end);

	if (_numbers.size() + count > _maxSize)
		throw FullException();
	_numbers.insert(_numbers.end(), begin, end);
}

#endif