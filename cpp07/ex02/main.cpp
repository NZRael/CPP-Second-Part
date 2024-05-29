/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:15:01 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/28 11:59:02 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	// Test de la construction par défaut
	try{
		Array<int> arr1;
		std::cout << "Array1 size: " << arr1.size() << std::endl;
		std::cout << "Array1 elements: ";
		for (unsigned int i = 0; i < arr1.size(); ++i)
			std::cout << arr1[i] << ", ";
		std::cout << std::endl;

		// Test de la construction avec un paramètre
		Array<int> arr2(5);
		std::cout << "Array2 size: " << arr2.size() << std::endl;
		std::cout << "Array2 elements: ";
		for (unsigned int i = 0; i < arr2.size(); ++i)
			std::cout << arr2[i] << ", ";
		std::cout << std::endl;

		// Incrementation sur l'array 2
		for (unsigned int i = 0; i < arr2.size(); ++i)
			arr2[i] = i + 1;

		// Test de la copie d'array 2
		Array<int> arr3(arr2);//= arr2;
		std::cout << "Array3 size: " << arr3.size() << std::endl;
		std::cout << "Array3 elements: ";
		for (unsigned int i = 0; i < arr3.size(); ++i)
			std::cout << arr3[i] << ", ";
		std::cout << std::endl;

		// Test de l'opérateur d'affectation sur array 2
		Array<int> arr4;
		arr4 = arr2;
		std::cout << "Array4 size: " << arr4.size() << std::endl;
		std::cout << "Array4 elements: ";
		for (unsigned int i = 0; i < arr4.size(); ++i)
			std::cout << arr4[i] << ", ";
		std::cout << std::endl;
		std::cout << std::endl;

		// Test d'un autre array avec plusieurs elements differents
		Array<std::string> arr5(10);
		std::cout << "Array5 size: " << arr5.size() << std::endl;
		std::cout << "Array5 elements basics : ";
		for (unsigned int i = 0; i < arr5.size(); ++i)
			std::cout << "'" << arr5[i] << "'" << ", ";
		arr5[2] = "Hello";
		arr5[5] = "World";
		std::cout << std::endl;
		std::cout << "Array5 elements changed: ";
		for (unsigned int i = 0; i < arr5.size(); ++i)
			std::cout << "'" << arr5[i] << "'" << ", ";
		std::cout << std::endl;
		arr5[10] = "Error";
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
