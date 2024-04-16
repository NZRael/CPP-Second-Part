#pragma once

#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
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

template <typename T>
typename T::iterator easyfind(T &container, int nb)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nb);
	if (it != container.end()) {
		return it;
	} else {
		throw std::runtime_error("Element not found");
	}
}
