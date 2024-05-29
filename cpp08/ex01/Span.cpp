#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &cpy) : _n(cpy._n), _tab(cpy._tab) {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_n = rhs._n;
		if (this->_n > 0)
			this->_tab = rhs._tab;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int nb){
	if (this->_n < 1)
		throw std::runtime_error("Nothing to turn in your list");
	if (this->_tab.size() >= this->_n)
		throw std::runtime_error("List is full");
	std::list<int>::iterator it;
	for (it = this->_tab.begin(); it != this->_tab.end(); it++) {
			if (*it == nb)
				throw std::runtime_error("Duplicated value");
	}
	this->_tab.push_back(nb);
}

void	Span::shortestSpan(){
	if (_tab.size() < 2) {
		throw std::runtime_error("Not enough int in the list for the shortest span");
	}
	std::list<int> sortedTab = this->_tab;
	sortedTab.sort();
	int shortest = std::numeric_limits<int>::max();
	std::list<int>::iterator it = sortedTab.begin();
	int prevVal = *it;
	++it;
	for (; it != sortedTab.end(); ++it) {
		int currentVal = *it; 
		int diff = currentVal - prevVal;
		if (diff < shortest) {
			shortest = diff;
		}
		prevVal = currentVal;
	}
	std::cout << GREEN <<"Shortest span in list is : " << shortest << RESET << std::endl;
}

void	Span::longestSpan(){
	if (_tab.size() < 2) {
		throw std::runtime_error("Not enough int in the list for the longest span");
	}
	std::list<int> sortedTab = _tab;
	sortedTab.sort();
	int minVal = sortedTab.front();
	int maxVal = sortedTab.back();
	int longest = maxVal - minVal;
	std::cout << GREEN << "Longest span in list is : " << longest << RESET << std::endl;
}

void	Span::betterAddNumber(std::list<int>::iterator begin, std::list<int>::iterator end){
	if (this->_n < 1)
		throw std::runtime_error("Nothing to turn in your list");
	if (this->_tab.size() >= this->_n)
		throw std::runtime_error("List is full");
	if (std::distance(begin, end) + this->_tab.size() > this->_n)
        throw std::runtime_error("Not enough space to add all elements");
	this->_tab.insert(this->_tab.end(), begin, end);
}
