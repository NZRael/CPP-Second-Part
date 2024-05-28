/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:22:33 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/27 13:16:20 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int		intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double	doubleArray[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.11};

	std::cout << "Int array after doubling each element:" << std::endl;
	iter(intArray, 10, doubleValue<int>);
	for (size_t i = 0; i < 10; ++i) {
		std::cout << intArray[i] << "|";
	}

	std::cout << std::endl;

	std::cout << "Double array after adding 1.0 to each element:" << std::endl;
	iter(doubleArray, 10, addOne<double>);
	for (size_t i = 0; i < 10; ++i) {
		std::cout << doubleArray[i] << "|";
	}

	std::cout << std::endl;

	return 0;
}
