#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	bitcoinExchange;

		bitcoinExchange.init_all(argv[1]);
	} catch (std::exception &exception) {
		std::cout << "[BitcoinExchange] ---- Exception caught!" << std::endl;
		std::cout << exception.what() << std::endl;
	}
}
