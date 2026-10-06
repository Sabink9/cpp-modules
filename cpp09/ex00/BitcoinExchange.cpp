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

bool		BitcoinExchange::isLeapYear(int year) const
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

// faire le restes des helpers et ensuite le input machin

void	BitcoinExchange::processInput(const std::string &filename)
{

}