#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	try {
		if (check_arg(argc, argv))
			return 1;
		PmergeMe pmergeMe;
		pmergeMe.processInput(argc, argv);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
