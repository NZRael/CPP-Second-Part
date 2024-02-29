/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:43:42 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/29 17:58:03 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(){
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;

	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("127");
	std::cout << std::endl;
	ScalarConverter::convert("COUCOU");
	std::cout << std::endl;
	ScalarConverter::convert("1 test");
	std::cout << std::endl;
	ScalarConverter::convert("C");

	return 0;
}
