#include "MutantStack.hpp"

#define BRED	"\033[1;31m"
#define BGRN	"\033[1;32m"
#define BYEL	"\033[1;33m"
#define BBLU	"\033[1;34m"
#define BMAG	"\033[1;35m"
#define BCYN	"\033[1;36m"
#define BWHT	"\033[1;37m"
#define CRESET	"\033[0m"

void	testSubject(void) {
	std::cout << BWHT ">>> RUNNING SUBJECT TESTS" CRESET << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << BCYN << mstack.top() << CRESET << std::endl;
	mstack.pop();
	std::cout << BCYN << mstack.size() << CRESET << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
}

void	runListIteration(void) {
	std::cout << BWHT ">>> LIST ITERATION" CRESET << std::endl;
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << BCYN << list.back() << CRESET << std::endl;
	list.pop_back();
	std::cout << BCYN << list.size() << CRESET << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int>	l(list);
}

int	main(void) {
	testSubject();
	runListIteration();

	std::cout << BYEL "All tests completed. The two outputs should be identical." CRESET << std::endl;
	return (0);
}
