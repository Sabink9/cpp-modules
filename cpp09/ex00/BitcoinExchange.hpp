#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
# include <map>
# include <string>
#include <fstream>
#include <exception>
#include <sstream>

enum e_valueStatus
{
	VALUE_OK,
	VALUE_BAD_INPUT,
	VALUE_NEGATIVE,
	VALUE_TOO_LARGE
};

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_database;

		std::string trim(const std::string &str) const;
		bool		isLeapYear(int year) const;
		bool		isValidDate(const std::string &date) const;
		e_valueStatus		isValidValue(const std::string &str, double &value) const;
		double		getRate(const std::string &date) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		void	processInput(const std::string &filename);
};

#endif