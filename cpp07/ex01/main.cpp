/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:22:33 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/14 12:02:47 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	// Using iter with intArray and doubleValue function
	std::cout << "Int array after doubling each element:" << std::endl;
	iter(intArray, 5, doubleValue<int>);
	for (size_t i = 0; i < 5; ++i) {
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Using iter with doubleArray and addOne function
	std::cout << "Double array after adding 1.0 to each element:" << std::endl;
	iter(doubleArray, 5, addOne<double>);
	for (size_t i = 0; i < 5; ++i) {
		std::cout << doubleArray[i] << "  ";
	}
	std::cout << std::endl;

	return 0;
}
