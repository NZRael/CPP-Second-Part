#pragma once

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
