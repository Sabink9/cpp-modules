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
	int	hasPoint = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (i == 0 && s[i] == '-')
				continue;
			if (s[i] == '.' && hasPoint == 0)
			{
				hasPoint++;
				continue;
			}
			return (false);
		}
		digiCount++;
	}
	if (digiCount > 0 && hasPoint == 1)
		return (true);
	else
		return (false);
}

static bool isFloat(std::string const& s)
{
	int	digiCount = 0;
	int	hasPoint = 0;
	int	hasF = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i] > 57)
		{
			if (i == 0 && s[i] == '-')
				continue;
			if (s[i] == '.' && hasPoint == 0)
			{
				hasPoint++;
				continue;
			}
			if (i == s.size() - 1 && s[i] == 'f')
			{
				hasF++;
				continue;
			}
			return (false);
		}
		digiCount++;
	}
	if (digiCount > 0 && hasPoint == 1 && hasF == 1)
		return (true);
	else
		return (false);
}

static bool isSpecialDouble(std::string const& s)
{
    return (s == "nan" || s == "inf" || s == "+inf" || s == "-inf");
}

static bool isSpecialFloat(std::string const& s)
{
    return (s == "nanf" || s == "inff" || s == "+inff" || s == "-inff");
}

static bool isNan(double value)
{
	return (value != value);
}

static bool isInf(double value)
{
	return (value == std::numeric_limits<double>::infinity()
	     || value == -std::numeric_limits<double>::infinity());
}

static void displayInt(double value)
{
	if (isNan(value) || isInf(value))
		std::cout << "int: impossible" << std::endl;
	else if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}
static void displayChar(double value)
{
	if (isNan(value) || isInf(value))
		std::cout << "char: impossible" << std::endl;
	else if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void displayDouble(double value)
{

	std::ostringstream oss;
	oss << value;
	std::string str = oss.str();
	
	if (str.find('.') == std::string::npos
		&& str.find("nan") == std::string::npos
		&& str.find("inf") == std::string::npos)
		str += ".0";

	std::cout << "double: " << str << std::endl;
}

static void displayFloat(double value)
{
	float f;

	if (isNan(value) || isInf(value))
		f = static_cast<float>(value);
	else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	else
		f = static_cast<float>(value);

	std::ostringstream oss;
	oss << f;
	std::string str = oss.str();

	if (str.find('.') == std::string::npos
		&& str.find("nan") == std::string::npos
		&& str.find("inf") == std::string::npos)
		str += ".0";

	std::cout << "float: " << str << "f" << std::endl;
}

static void handleChar(std::string const& literal)
{
	char c = literal[1];
	double value = static_cast<double>(c);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

static void handleInt(std::string const& literal)
{
	std::stringstream ss(literal);
	long l;
	ss >> l;
	double value = static_cast<double>(l);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

static void handleFloat(std::string const& literal)
{
	std::stringstream ss(literal);
	float f;
	ss >> f;
	double value = static_cast<double>(f);

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

static void handleDouble(std::string const& literal)
{
	std::stringstream ss(literal);
	double value;
	ss >> value;

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

static void handleSpecialFloat(std::string const& literal)
{
	double value;
	if (literal == "nanf")
		value = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "inff" || literal == "+inff")
		value = std::numeric_limits<float>::infinity();
	else
		value = -std::numeric_limits<float>::infinity();
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}
static void handleSpecialDouble(std::string const& literal)
{
	double value;
	if (literal == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "+inf")
		value = std::numeric_limits<double>::infinity();
	else
		value = -std::numeric_limits<double>::infinity();
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::convert(std::string const& literal)
{
	if (isChar(literal))
		handleChar(literal);
	else if (isInt(literal))
		handleInt(literal);
	else if (isSpecialFloat(literal))
		handleSpecialFloat(literal);
	else if (isFloat(literal))
		handleFloat(literal);
	else if (isSpecialDouble(literal))
		handleSpecialDouble(literal);
	else if (isDouble(literal))
		handleDouble(literal);
	else
		std::cout << "Impossible to convert" << std::endl;
}