#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& cpy){
	*this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){
	(void)rhs;
	return *this;
}

PmergeMe::~PmergeMe(){
}

bool	check_arg(int argc, char** argv){
	if (argc <= 2){
		std::cerr << "Usage: ./PmergeMe [numbers...]" << std::endl;
		throw PmergeMe::invalidArgumentError();
	}
	for (int i = 1; i < argc; i++){
		std::string str(argv[i]);
		for (size_t j = 0; j < str.size(); j++){
			if (!std::isdigit(str[j]))
				throw PmergeMe::invalidArgumentError();
		}
		char	*end;
		long	lim = std::strtol(str.c_str(), &end, 10);
		if (lim > INT_MAX || lim < INT_MIN)
			throw PmergeMe::invalidArgumentError();
	}
	//boucle pour checker si il y a des doublons dans les nombres
	for (int i = 1; i < argc; i++){
		for (int j = i + 1; j < argc; j++){
			if (std::atoi(argv[i]) == std::atoi(argv[j]))
				throw PmergeMe::duplicatesError();
		}
	}
	return 0;
}

template <typename Container>
void	PmergeMe::printContainer(const Container& container){
	for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::parseInput(int argc, char** argv){
	std::vector<int> numbers;
	for (int i = 1; i < argc; i++)
		numbers.push_back(std::atoi((argv[i])));
	return numbers;
}

template <typename Container>
void	PmergeMe::fordJohnsonSort_vec(Container& container){
	size_t	size = container.size();
	int		spare = -1;
	if (size % 2 != 0){
		spare = container[size - 1];
		container.pop_back();
		size--;
	}
	// Mettre les valeures rangee par paire dans un vecteur de pairs
	std::vector<std::pair<int, int> > vecpairs;
	for (size_t i = 0; i < size; i += 2)
		vecpairs.push_back(std::make_pair(container[i], container[i + 1]));
	// Trier les deux valeures de chaque pair
	for (size_t i = 0; i < vecpairs.size(); i++){
		if (vecpairs[i].first > vecpairs[i].second)
			std::swap(vecpairs[i].first, vecpairs[i].second);
	}
	// ///////////////AFFICHAGE
	// std::cout << "Pairs after sort in them" << std::endl;
	// for (std::Container<std::pair<int, int> >::iterator it_pair = vecpairs.begin(); it_pair != vecpairs.end(); it_pair++)
	// 	std::cout << "[" << it_pair->first << " " << it_pair->second << "] ";
	// std::cout << std::endl;
	// ////////////////////////
	// Trier les pairs par rapport a la deuxieme valeur
	for (size_t i = 0; i < vecpairs.size(); i++){
		for (size_t j = i + 1; j < vecpairs.size(); j++){
			if (vecpairs[i].second > vecpairs[j].second)
				std::swap(vecpairs[i], vecpairs[j]);
		}
	}
	// ///////////////AFFICHAGE
	// std::cout << "Sort Pairs by second element" << std::endl;
	// for (std::Container<std::pair<int, int> >::iterator it_pair = vecpairs.begin(); it_pair != vecpairs.end(); it_pair++)
	// 	std::cout << "[" << it_pair->first << " " << it_pair->second << "] ";
	// std::cout << std::endl;
	// ////////////////////////
	// Mettre les valeurs min dans un vecteur et les valeurs max dans un autre
	Container tmp_MinVec;
	Container maxVec;
	for (size_t i = 0; i < vecpairs.size(); i++){
		tmp_MinVec.push_back(vecpairs[i].first);
		maxVec.push_back(vecpairs[i].second);
	}
	if (spare != -1)
		tmp_MinVec.push_back(spare);
	// ///////////////AFFICHAGE
	// std::cout << "Container of MAX pair before" << std::endl;
	// for (std::Container<int>::iterator it = maxVec.begin(); it != maxVec.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// ////////////////////////
	// ///////////////AFFICHAGE
	// std::cout << "Container of MIN pair before" << std::endl;
	// for (Container<int>::iterator it = tmp_MinVec.begin(); it != tmp_MinVec.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// ////////////////////////
	// Commencement du tri
	if (tmp_MinVec.size() > 2){
		merge(maxVec, tmp_MinVec[0], 0, 0);
		merge(maxVec, tmp_MinVec[1], 0, 1);
		typename Container::iterator begin = tmp_MinVec.begin() + 2;
		int	nextsuite = 2;
		int	suite = 2;
		int	lastsuite = 0;
		int 	size_left = tmp_MinVec.size() - 2;
		// Quand la liste de nombres est paire
		if (spare == -1){
			while (1){
				typename Container::iterator end = begin;
				typename Container::iterator ite = begin;
				if (size_left <= nextsuite){
					end = begin + size_left - 1;
					for (; end != begin - 1; end--){
						merge(maxVec, *end, 0, search_maxIndex_vec(maxVec, vecpairs, end));
					}
					break ;
				}
				end = begin + nextsuite - 1;
				ite = end + 1;
				for (; end != begin - 1; end--){
					merge(maxVec, *end, 0, search_maxIndex_vec(maxVec, vecpairs, end));
				}
				suite = nextsuite;
				nextsuite = lastsuite * 2 + suite;
				lastsuite = suite;
				size_left -= suite;
				begin = ite;
			}
		}
		// Quand la liste de nombres est impaire
		else{
			while (1){
				typename Container::iterator end = begin;
				typename Container::iterator ite = begin;
				if (size_left <= nextsuite){
					end = begin + size_left - 1;
					merge(maxVec, *end, 0, maxVec.size());
					end--;
					for (; end != begin - 1; end--){
						merge(maxVec, *end, 0, search_maxIndex_vec(maxVec, vecpairs, end));
					}
					break ;
				}
				end = begin + nextsuite - 1;
				ite = end + 1;
				for (; end != begin - 1; end--){
					merge(maxVec, *end, 0, search_maxIndex_vec(maxVec, vecpairs, end));
				}
				suite = nextsuite;
				nextsuite = lastsuite * 2 + suite;
				lastsuite = suite;
				size_left -= suite;
				begin = ite;
			}
		}
	}
	else{
		merge(maxVec, tmp_MinVec[0], 0, 0);
		merge(maxVec, tmp_MinVec[1], 0, 1);
	}
	container.clear();
	container.insert(container.begin(), maxVec.begin(), maxVec.end());
	// std::cout << std::endl;
}

template <typename Container>
void	PmergeMe::fordJohnsonSort_deq(Container& container){
	size_t	size = container.size();
	int		spare = -1;
	if (size % 2 != 0){
		spare = container[size - 1];
		container.pop_back();
		size--;
	}
	// Mettre les valeures rangee par paire dans un vecteur de pairs
	std::deque<std::pair<int, int> > deqpairs;
	for (size_t i = 0; i < size; i += 2)
		deqpairs.push_back(std::make_pair(container[i], container[i + 1]));
	// Trier les deux valeures de chaque pair
	for (size_t i = 0; i < deqpairs.size(); i++){
		if (deqpairs[i].first > deqpairs[i].second)
			std::swap(deqpairs[i].first, deqpairs[i].second);
	}
	// ///////////////AFFICHAGE
	// std::cout << "Pairs after sort in them" << std::endl;
	// for (std::Container<std::pair<int, int> >::iterator it_pair = deqpairs.begin(); it_pair != deqpairs.end(); it_pair++)
	// 	std::cout << "[" << it_pair->first << " " << it_pair->second << "] ";
	// std::cout << std::endl;
	// ////////////////////////
	// Trier les pairs par rapport a la deuxieme valeur
	for (size_t i = 0; i < deqpairs.size(); i++){
		for (size_t j = i + 1; j < deqpairs.size(); j++){
			if (deqpairs[i].second > deqpairs[j].second)
				std::swap(deqpairs[i], deqpairs[j]);
		}
	}
	// ///////////////AFFICHAGE
	// std::cout << "Sort Pairs by second element" << std::endl;
	// for (std::Container<std::pair<int, int> >::iterator it_pair = deqpairs.begin(); it_pair != deqpairs.end(); it_pair++)
	// 	std::cout << "[" << it_pair->first << " " << it_pair->second << "] ";
	// std::cout << std::endl;
	// ////////////////////////
	// Mettre les valeurs min dans un vecteur et les valeurs max dans un autre
	Container tmp_MinVec;
	Container maxVec;
	for (size_t i = 0; i < deqpairs.size(); i++){
		tmp_MinVec.push_back(deqpairs[i].first);
		maxVec.push_back(deqpairs[i].second);
	}
	if (spare != -1)
		tmp_MinVec.push_back(spare);
	// ///////////////AFFICHAGE
	// std::cout << "Container of MAX pair before" << std::endl;
	// for (std::Container<int>::iterator it = maxVec.begin(); it != maxVec.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// ////////////////////////
	// ///////////////AFFICHAGE
	// std::cout << "Container of MIN pair before" << std::endl;
	// for (Container<int>::iterator it = tmp_MinVec.begin(); it != tmp_MinVec.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// ////////////////////////
	// Commencement du tri
	if (tmp_MinVec.size() > 2){
		merge(maxVec, tmp_MinVec[0], 0, 0);
		merge(maxVec, tmp_MinVec[1], 0, 1);
		typename Container::iterator begin = tmp_MinVec.begin() + 2;
		int	nextsuite = 2;
		int	suite = 2;
		int	lastsuite = 0;
		int 	size_left = tmp_MinVec.size() - 2;
		// Quand la liste de nombres est paire
		if (spare == -1){
			while (1){
				typename Container::iterator end = begin;
				typename Container::iterator ite = begin;
				if (size_left <= nextsuite){
					end = begin + size_left - 1;
					for (; end != begin - 1; end--){
						merge(maxVec, *end, 0, search_maxIndex_deq(maxVec, deqpairs, end));
					}
					break ;
				}
				end = begin + nextsuite - 1;
				ite = end + 1;
				for (; end != begin - 1; end--){
					merge(maxVec, *end, 0, search_maxIndex_deq(maxVec, deqpairs, end));
				}
				suite = nextsuite;
				nextsuite = lastsuite * 2 + suite;
				lastsuite = suite;
				size_left -= suite;
				begin = ite;
			}
		}
		// Quand la liste de nombres est impaire
		else{
			while (1){
				typename Container::iterator end = begin;
				typename Container::iterator ite = begin;
				if (size_left <= nextsuite){
					end = begin + size_left - 1;
					merge(maxVec, *end, 0, maxVec.size());
					end--;
					for (; end != begin - 1; end--){
						merge(maxVec, *end, 0, search_maxIndex_deq(maxVec, deqpairs, end));
					}
					break ;
				}
				end = begin + nextsuite - 1;
				ite = end + 1;
				for (; end != begin - 1; end--){
					merge(maxVec, *end, 0, search_maxIndex_deq(maxVec, deqpairs, end));
				}
				suite = nextsuite;
				nextsuite = lastsuite * 2 + suite;
				lastsuite = suite;
				size_left -= suite;
				begin = ite;
			}
		}
	}
	else{
		merge(maxVec, tmp_MinVec[0], 0, 0);
		merge(maxVec, tmp_MinVec[1], 0, 1);
	}
	container.clear();
	container.insert(container.begin(), maxVec.begin(), maxVec.end());
	// std::cout << std::endl;
}

template <typename Container>
int		PmergeMe::search_maxIndex_vec(Container &maxVec, std::vector<std::pair<int, int> > vecpairs, const typename Container::iterator& it){
	int	index = 0;
	for (typename std::vector<std::pair<int, int> >::iterator it_pair = vecpairs.begin(); it_pair != vecpairs.end(); it_pair++){
		if (it_pair->first == *it){
			for (typename Container::iterator it_max = maxVec.begin(); it_max != maxVec.end(); it_max++){
				if (*it_max == it_pair->second){
					return index;
				}
				index++;
			}
		}
	}
	return -1;
}

template <typename Container>
int		PmergeMe::search_maxIndex_deq(Container &maxVec, std::deque<std::pair<int, int> > deqpairs, const typename Container::iterator& it){
	int	index = 0;
	for (typename std::deque<std::pair<int, int> >::iterator it_pair = deqpairs.begin(); it_pair != deqpairs.end(); it_pair++){
		if (it_pair->first == *it){
			for (typename Container::iterator it_max = maxVec.begin(); it_max != maxVec.end(); it_max++){
				if (*it_max == it_pair->second){
					return index;
				}
				index++;
			}
		}
	}
	return -1;
}

template <typename Container>
void	PmergeMe::merge(Container& all, int value, int start, int end){
	if (start == end){
		all.insert(all.begin() + start, value);
		return ;
	}
	int	mid = (start + end) / 2;
	if (value < all[mid])
		merge(all, value, start, mid);
	else
		merge(all, value, mid + 1, end);
}

void	PmergeMe::processInput(int argc, char** argv){
	std::vector<int> numbers = parseInput(argc, argv);
	std::cout << "Before : ";
	printContainer(numbers);

	std::vector<int> vecContainer = numbers;
	std::deque<int> deqContainer(numbers.begin(), numbers.end());

	std::clock_t start_vec = std::clock();
	fordJohnsonSort_vec(vecContainer);
	std::clock_t end_vec = std::clock();

	std::clock_t start_deq = std::clock();
	fordJohnsonSort_deq(deqContainer);
	std::clock_t end_deq = std::clock();

	std::cout << "After : ";
	printContainer(vecContainer);

	double vecDuration = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000.0;
	double deqDuration = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000.0;

	std::cout << "Time to process a range of " << numbers.size()
			<< " elements with a vector: " << vecDuration << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers.size()
			<< " elements with a deque: " << deqDuration << " us" << std::endl;
}
