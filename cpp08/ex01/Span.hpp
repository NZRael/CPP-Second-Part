#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <limits>
#include <list>

#define RESET "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Span{
	private:
		unsigned int	_n;
		std::list<int>	_tab;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &cpy);
		Span &operator=(const Span &rhs);
		~Span();
		
		void	addNumber(int nb);
		void	shortestSpan();
		void	longestSpan();
};
