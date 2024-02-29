/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:28:08 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/29 12:43:28 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout <<  "Default constructor ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy){
	std::cout <<  "Copy constructor ScalarConverter called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs){
	std::cout <<  "Constructor ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(){
	std::cout <<  "Destructor ScalarConverter called" << std::endl;
}

void	ScalarConverter::convert(std::string str){
	
}
