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
		float	ft_stof(std::string str);
		bool	validDate(std::string date, std::string line);
		bool	validValue(std::string value, std::string line);
		float	exchangeRate(std::string date);
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & src);
		~BitcoinExchange();

		void	printExchange(char *file_name);
		void	init_data(std::string filename);
};
