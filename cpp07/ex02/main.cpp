/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:15:01 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/14 14:09:20 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main() {
	// Test de la construction par défaut
	Array<int> arr1;
	std::cout << "Array 1 size: " << arr1.size() << std::endl;
	std::cout << "Array 1 elements: ";
	for (unsigned int i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << ", ";
	}
	std::cout << std::endl;

	// Test de la construction avec un paramètre
	Array<int> arr2(5);
	std::cout << "Array 2 size: " << arr2.size() << std::endl;
	std::cout << "Array 2 elements: ";
	for (unsigned int i = 0; i < arr2.size(); ++i) {
		std::cout << arr2[i] << ", ";
	}
	std::cout << std::endl;

	// Incrementation sur l'array 2
	for (unsigned int i = 0; i < arr2.size(); ++i) {
		arr2[i] = i + 1;
	}

	// Test de la copie d'array 2
	Array<int> arr3 = arr2;
	std::cout << "Array 3 size: " << arr3.size() << std::endl;
	std::cout << "Array 3 elements: ";
	for (unsigned int i = 0; i < arr3.size(); ++i) {
		std::cout << arr3[i] << ", ";
	}
	std::cout << std::endl;

	// Test de l'opérateur d'affectation sur array 2
	Array<int> arr4;
	arr4 = arr2;
	std::cout << "Array 4 size: " << arr4.size() << std::endl;
	std::cout << "Array 4 elements: ";
	for (unsigned int i = 0; i < arr4.size(); ++i) {
		std::cout << arr4[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	// Test de l'accès à un élément hors limites (devrait lancer une exception)
	try {
		std::cout << "Trying to access element arr2[10]: " << arr2[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
