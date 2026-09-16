#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		ScalarConverter& operator=(ScalarConverter const& other);
		~ScalarConverter();
	public:
		static void convert(std::string const& literal);
};

#endif