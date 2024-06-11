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
};

bool	check_arg(int argc, char** argv);

// 10 1   4 58   56 44   45 2   5 0   23 11

// 1 10   4 58   44 56   2 45   0 5   11 23

// 0 5    1 10   11 23   2 45   44 56  4 58

// 5 10 23 45 56 58           0 1 11 2 44 4

// [1 0]   [2 11]   [4 44] [X X X X X X]

// 1 0     11 2     44 4     
