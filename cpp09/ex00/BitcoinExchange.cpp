#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src){
	if (this != &src){
		this->_data = src._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
}

int		BitcoinExchange::ft_stoi(std::string str){
	int i;

	std::istringstream(str) >> i;
	return i;
}

float		BitcoinExchange::ft_stof(std::string str){
	float f;

	std::istringstream(str) >> f;
	return f;
}

void	BitcoinExchange::init_data(std::string filename){
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	while (std::getline(file, line)){
		if (!line.compare("date,exchange_rate"))
			continue;
		std::istringstream iss(line);
		std::string		date, exchange_rate;

		if (std::getline(iss, date, ',') && std::getline(iss, exchange_rate))
			this->_data.insert(std::make_pair(date, ft_stof(exchange_rate)));
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	file.close();
}

bool	BitcoinExchange::validValue(std::string value, std::string line){
	int	dot = 1;

	if (value.empty()){
		std::cerr << "Error: bad input value => " << line << std::endl;
		return false;
	}
	for (size_t i = 1; i < value.length(); i++){
		if (value[i] == '.'){
			if (!dot){
				std::cerr << "Error: bad input (value must be in float) => " << line << std::endl;
				return false;
			}
			dot = 0;
		}
		else if (!std::isdigit(value[i])){
			std::cerr << "Error: bad value format (value must be in float) => " << line << std::endl;
			return false;
		}
	}
	return true;
}


bool	BitcoinExchange::validDate(std::string date, std::string line){
	int	year = ft_stoi(date.substr(0, 4));
	int	month = ft_stoi(date.substr(5, 2));
	int	day = ft_stoi(date.substr(8, 2));
	int	days_of_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
	if (day < 1 || day > days_of_months[month - 1]){
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

float	BitcoinExchange::exchangeRate(std::string date){
	std::map<std::string, float>::iterator it = this->_data.lower_bound(date);

	if (date != it->first && it != this->_data.begin())
		it--;
	if (it == this->_data.end())
		it--;
	return (it->second);
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
		std::istringstream iss(line);
		std::string		date, value;
		if (std::getline(iss, date, '|') && std::getline(iss, value)){
			if (!validDate(date, line))
				continue ;
			if (line[date.length()] != '|'){
				std::cerr << "Error: bad input => " << line << std::endl;
				continue ;
			}
			if (!validValue(value, line))
				continue ;
			float	fvalue = ft_stof(value);
			if (fvalue < 0){
				std::cerr << "Error: not a positive number." << std::endl;
				continue ;
			}
			if (fvalue > 1000){
				std::cerr << "Error: too large a number." << std::endl;
				continue ;
			}
			float	exchange_rate = exchangeRate(date);
			std::cout << date << "=>" << value << " = " << (exchange_rate * fvalue) << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}
