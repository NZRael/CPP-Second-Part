#include "Span.hpp"

int main() {
	try {
		Span span1(5);

		std::cout << YELLOW << "First test: Adding numbers to Span1:" << RESET << std::endl;
		span1.addNumber(0);
		span1.addNumber(-1);
		span1.addNumber(15);
		span1.addNumber(8);
		span1.addNumber(-20);

		std::cout << "Calculating shortest distance for Span1:" << std::endl;
		span1.shortestSpan();

		std::cout << "Calculating longest distance for Span1:" << std::endl;
		span1.longestSpan();

		std::cout << std::endl;

		Span span2(10000);
		std::cout << YELLOW << "Second test: Adding more than 10,000 numbers to Span2:" << RESET << std::endl;
		for (int i = 0; i < 10000; ++i) {
			span2.addNumber(i);
		}

		std::cout << "Calculating shortest distance for Span2:" << std::endl;
		span2.shortestSpan();

		std::cout << "Calculating longest distance for Span2:" << std::endl;
		span2.longestSpan();

		std::cout << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		Span emptySpan;
		std::cout << YELLOW << "Test with an empty list: " << RESET << std::endl;
		emptySpan.shortestSpan();
		emptySpan.longestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}

