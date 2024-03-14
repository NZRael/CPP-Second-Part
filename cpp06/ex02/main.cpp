/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:40 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/12 16:01:44 by sboetti          ###   ########.fr       */
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
	if (dynamic_cast<A*>(&p) != 0) {
		std::cout << "Type: A" << std::endl;
	} else if (dynamic_cast<B*>(&p) != 0) {
		std::cout << "Type: B" << std::endl;
	} else if (dynamic_cast<C*>(&p) != 0) {
		std::cout << "Type: C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

int main() {
	A objA;
	B objB;
	C objC;

	identify(objA); // Affichera "Type: A"
	identify(objB); // Affichera "Type: B"
	identify(objC); // Affichera "Type: C"

	std::cout << std::endl;

	Base* obA = new A();
	Base* obB = new B();
	Base* obC = new C();

	identify(obA); // Affichera "Type: A"
	identify(obB); // Affichera "Type: B"
	identify(obC); // Affichera "Type: C"

	delete obA;
	delete obB;
	delete obC;

	return 0;
}
