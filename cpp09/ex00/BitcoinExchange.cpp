#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src){
	(void)src;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

int		BitcoinExchange::ft_stoi(std::string str){
	int i;

	std::istringstream(str) >> i;
	return i;
}

bool	BitcoinExchange::validDate(std::string date, std::string line){
	int	year = ft_stoi(date.substr(0, 4));
	int	month = ft_stoi(date.substr(5, 2));
	int	day = ft_stoi(date.substr(8, 2));

	if (date.length() != 11){
		std::cerr << "Error: bad date format (format = 'YYYY-MM-DD ') => "  << line << std::endl;
		return false;
	}
	if (date[4] != '-' || date[7] != '-' || date[10] != ' '){
		std::cerr << "Error: bad date format (format = 'YYYY-MM-DD ') => " << line << std::endl;
		return false;
	}
	if (year < 2008 || year > 2024){
		std::cerr << "Error: bad date format (year) => " << line << std::endl;
		return false;
	}
	if (month < 1 || month > 12){
		std::cerr << "Error: bad date format (month) => " << line << std::endl;
		return false;
	}
	if (day < 1 || day > 31){
		std::cerr << "Error: bad date format (day) => " << line << std::endl;
		return false;
	}
	if (year == 2008 && (month < 10 || day < 31)){
		std::cerr << "Error: bad date format (btc not created) => " << line << std::endl;
		return false;
	}
	for (int i = 0; i < 10; i++){
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9'){
			std::cerr << "Error: bad date format (date must be in int) => " << line << std::endl;
			return false;
		}
	}
	return true;
}

void	BitcoinExchange::printExchange(char *file_name){
	std::ifstream	file(file_name);
	std::string		line;

	if (!file.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	while (std::getline(file, line)){
		if (!line.compare("date | value"))
			continue;
		std::cout << "line = '" << line + '\'' << std::endl;
		std::istringstream iss(line);
		std::string		date, value;
		if (std::getline(iss, date, '|') && std::getline(iss, value)){
			// std::cout << "date = " << '\'' + date + '\'' << std::endl;
			// std::cout << "value = " << '\'' + value + '\'' << std::endl;
			if (validDate(date, line) && line[date.length()] == '|'/* && validValue(value)*/){
				std::cout << "valid line frero" << std::endl;
				continue ;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}

void	BitcoinExchange::init_all(char *file_name){
	printExchange(file_name);
}
