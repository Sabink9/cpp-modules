#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _database()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream myReadFile(filename.c_str());
	if (!myReadFile.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	std::string date;
	std::string rateStr;
	std::getline (myReadFile, line);
	while (std::getline (myReadFile, line))
	{
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue ;
		date = line.substr(0, comma);
		rateStr = line.substr(comma + 1);
		std::stringstream ss(rateStr);
		double rate;
		ss >> rate;
		_database[date] = rate;
	}
	myReadFile.close();
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return (true);
			return (false);
		}
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	int	year, month, day;

	if (date.size() == 10)
	{
		if (date[4] != '-' || date[7] != '-')
			return (false);
		for (int i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7)
				continue;
			if (!isdigit(static_cast<unsigned char>(date[i])))
				return (false);
		}
		year = std::atoi(date.substr(0, 4).c_str());
		month = std::atoi(date.substr(5, 2).c_str());
		day = std::atoi(date.substr(8, 2).c_str());

		if (month > 12 || month < 1)
			return (false);
		if (day < 1)
			return (false);
		if (month == 2)
		{
			if (isLeapYear(year))
			{
				if (day > 29)
					return (false);
			}
			else if (day > 28)
				return (false);
		}
		else if (month >= 1 && month <= 7)
		{
			if (month % 2 == 0)
			{
				if (day > 30)
					return (false);
			}
			else if (day > 31)
				return (false);
		}
		else
		{
			if (month % 2 == 0)
			{
				if (day > 31)
					return (false);
			}
			else if (day > 30)
				return (false);
		}
		return (true);
	}
	return (false);
}


e_valueStatus	BitcoinExchange::isValidValue(const std::string &str, double &value) const
{
	std::stringstream ss(str);
	
	ss >> value;
	if (ss.fail())
		return (VALUE_BAD_INPUT);
	char c;
	if (ss >> c)
		return (VALUE_BAD_INPUT);
	if (value > 1000)
		return (VALUE_TOO_LARGE);
	if (value < 0)
		return (VALUE_NEGATIVE);

	return (VALUE_OK);
}

void	BitcoinExchange::processInput(const std::string &filename)
{

}