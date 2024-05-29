#pragma once

#define BRED	"\033[1;31m"
#define BGRN	"\033[1;32m"
#define BYEL	"\033[1;33m"
#define BBLU	"\033[1;34m"
#define BMAG	"\033[1;35m"
#define BCYN	"\033[1;36m"
#define BWHT	"\033[1;37m"
#define CRESET	"\033[0m"

#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
		MutantStack() : std::stack<T, Container>(){};
		MutantStack(const MutantStack &cpy) : std::stack<T, Container>(cpy){};
		MutantStack &operator=(const MutantStack &other){
			std::stack<T, Container>::operator=(other);
		};
		~MutantStack(){};

		typedef typename Container::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};
