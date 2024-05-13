#include "BitcoinExchange.hpp"

void	ft_check_file(char *file_name){
	std::ifstream	file(file_name);
	std::string		line;

	if (!file.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	//print le fichier
	while (std::getline(file, line)){
		std::cout << "line = '" << line + '\'' << std::endl;
		std::istringstream iss(line);
		std::string		date, value;
		if (std::getline(iss, date, '|') && std::getline(iss, value)){
			date.erase(date.find_last_not_of(" ") + 1);
			std::cout << "date = " << '\'' + date + '\'' << std::endl;
			std::cout << "value = " << '\'' + value + '\'' << std::endl;
			value.erase(date.find_first_not_of(" "));
			std::cout << "value = " << '\'' + value + '\'' << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	//check des dates etc

}

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	ft_check_file(argv[1]);
}
