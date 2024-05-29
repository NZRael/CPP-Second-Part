#include "Span.hpp"

int main() {
	try {
		Span span1(5);

		std::cout << YELLOW << "-----First test: Adding numbers to Span1:" << RESET << std::endl;
		span1.addNumber(0);
		span1.addNumber(-1);
		span1.addNumber(15);
		span1.addNumber(8);
		span1.addNumber(-20);

		span1.shortestSpan();
		span1.longestSpan();

		std::cout << std::endl;

		Span span2(10000);
		std::cout << YELLOW << "-----Second test: Adding 10,000 numbers to Span2:" << RESET << std::endl;
		for (int i = 0; i < 10000; i += 1) {
			span2.addNumber(i);
		}

		span2.shortestSpan();

		span2.longestSpan();

		std::cout << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl << std::endl;
	}
	try {
		std::cout << YELLOW << "-----Third test: Test the better function to addNumber: " << RESET << std::endl;
		Span betterSpan(10);

		std::list<int> betterList;
		betterList.push_back(70);
		betterList.push_back(2);
		betterList.push_back(3);
		betterList.push_back(4);
		betterList.push_back(5);
		betterList.push_back(6);
		betterList.push_back(7);
		betterList.push_back(8);
		betterList.push_back(989);
		betterList.push_back(10);
		betterSpan.betterAddNumber(betterList.begin(), betterList.end());
		betterSpan.shortestSpan();
		betterSpan.longestSpan();
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try {
		Span emptySpan;
		std::cout << YELLOW << "-----Test with an empty list: " << RESET << std::endl;
		emptySpan.shortestSpan();
		emptySpan.longestSpan();
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}
