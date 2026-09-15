#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(std::string const& s)
{
    return (s.size() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isInt(std::string const& s)
{
	int	digiCount = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (i == 0 && s[i] == '-')
				continue;
			return (false);
		}
		if (s[i] >= 48 && s[i] <= 57)
			digiCount++;
	}
	if (digiCount > 0)
		return (true);
	else
		return (false);
}

static bool isDouble(std::string const& s)
{
	int	digiCount = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (i == 0 && s[i] == '-')
				continue;
			// blablabla
			return (false);
		}
		if (s[i] >= 48 && s[i] <= 57)
			digiCount++;
	}
	if (digiCount > 0)
		return (true);
	else
		return (false);
}

static bool isFloat(std::string const& s)
{
	int	digiCount = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (i == 0 && s[i] == '-')
				continue;
			// blablabla
			return (false);
		}
		if (s[i] >= 48 && s[i] <= 57)
			digiCount++;
	}
	if (digiCount > 0)
		return (true);
	else
		return (false);
}

void ScalarConverter::convert(std::string const& literal)
{

}