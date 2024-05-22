#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange{
	private:
		std::map<std::string, float>	_data;

		int		ft_stoi(std::string str);
		bool	validDate(std::string date, std::string line);
		bool	validValue(std::string value);
		void	printExchange(char *file_name);
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & src);
		~BitcoinExchange();

		void	init_all(char *file_name);
};
