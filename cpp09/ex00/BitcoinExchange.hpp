#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
# include <map>
# include <string>
#include <fstream>
#include <exception>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_database;

		std::string trim(const std::string &str) const;
		bool		isLeapYear(int year) const;
		bool		isValidDate(const std::string &date) const;
		bool		isValidValue(const std::string &str, double &value) const;
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