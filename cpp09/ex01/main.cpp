#include "RPN.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage: ./RPN [inverted Polish mathematical expression]" << std::endl;
		return 1;
	}
	std::string str = argv[1];
	if (!check_expression(str)){
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}