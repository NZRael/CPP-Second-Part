#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>

class	PmergeMe{
	private:
		std::vector<int> parseInput(int argc, char** argv);

		template <typename Container>
		void fordJohnsonSort_vec(Container& container);

		template <typename Container>
		void fordJohnsonSort_deq(Container& container);

		template <typename Container>
		void printContainer(const Container& container);

		template <typename Container>
		void	merge(Container& all, int value, int start, int end);

		template <typename Container>
		int	search_maxIndex_vec(Container &maxVec, std::vector<std::pair<int, int> > vecpairs, const typename Container::iterator& it);

		template <typename Container>
		int	search_maxIndex_deq(Container &maxVec, std::deque<std::pair<int, int> > deqpairs, const typename Container::iterator& it);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void processInput(int argc, char** argv);
		class invalidArgumentError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: invalid argument");
				}
		};
		class duplicatesError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("[Error]: duplicates are forbidden");
				}
		};
};

bool	check_arg(int argc, char** argv);
