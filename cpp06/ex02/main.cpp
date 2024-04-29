/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:40 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/29 16:20:19 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void){
	std::srand(static_cast<unsigned int>(std::time(0)));
	int randVal = std::rand();

	if (randVal % 3 == 0)
		return new A;
	else if (randVal % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p){
	if (A* ptr = dynamic_cast<A*>(p)) {
		std::cout << "Type: A" << std::endl;
	} else if (B* ptr = dynamic_cast<B*>(p)) {
		std::cout << "Type: B" << std::endl;
	} else if (C* ptr = dynamic_cast<C*>(p)) {
		std::cout << "Type: C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void	identify(Base &p){
	try{
		if (dynamic_cast<A*>(&p) != 0) {
			std::cout << "Type: A" << std::endl;
		} else if (dynamic_cast<B*>(&p) != 0) {
			std::cout << "Type: B" << std::endl;
		} else if (dynamic_cast<C*>(&p) != 0) {
			std::cout << "Type: C" << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Unknown type" << e.what() << std::endl;
	}
}

int main() {
	Base	*base;

	std::cout << "RUNNING SUBJECT TESTS" << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "All tests completed" << std::endl;
	return 0;
}
