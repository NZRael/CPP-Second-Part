#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange	bitcoinExchange;

	bitcoinExchange.init_data("data.csv");
	bitcoinExchange.printExchange(argv[1]);
	return (0);
}
