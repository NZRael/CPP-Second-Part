#include "MutantStack.hpp"

void	testSubject(void) {
	std::cout << BWHT "---- RUNNING SUBJECT TESTS" CRESET << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << BCYN << "top => " << mstack.top() << CRESET << std::endl;
	mstack.pop();
	std::cout << BCYN << "size => " << mstack.size() << CRESET << std::endl;
	
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
	std::cout << BWHT "---- LIST ITERATION" CRESET << std::endl;
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);

	std::cout << BCYN << "back => " << list.back() << CRESET << std::endl;
	list.pop_back();
	std::cout << BCYN << "size => " << list.size() << CRESET << std::endl;

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
}

int	main(void) {
	testSubject();
	runListIteration();

	std::cout << BYEL "All tests completed. The two outputs should be identical." CRESET << std::endl;
	return (0);
}
