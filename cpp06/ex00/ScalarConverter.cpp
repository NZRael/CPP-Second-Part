/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:35:39 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/29 18:39:58 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout <<  "Constructor ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy){
	std::cout <<  "Copy constructor ScalarConverter called" << std::endl;
	*this = cpy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs){
	std::cout <<  "Constructor ScalarConverter called" << std::endl;
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){
	std::cout <<  "Destructor ScalarConverter called" << std::endl;
}

void	ScalarConverter::convertChar(std::string str){
	if (str.length() == 1 && !std::isdigit(str[0]))
		std::cout << "char: " << str[0] << std::endl;
	else if (std::atoi(str.c_str()) > 0 && std::atoi(str.c_str()) < 127)
		std::cout << "char: " << static_cast<char>(std::atoi(str.c_str())) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;	
}

void	ScalarConverter::convertInt(std::string str){
	int	i;

	i = std::atoi(str.c_str());
	if (i == 0 && str[0] != '0')
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

bool	ScalarConverter::checkInt(std::string str){
	if (str[0] == '-' || str[0] == '+')
		return std::isdigit(str[1]);
	return std::isdigit(str[0]);
}

LiteralType	ScalarConverter::checkType(std::string str){
	if (literal.empty())
		return NO_TYPE;
	if (literal.length() == 1 && std::isalpha(literal[0]))
		return CHAR_TYPE;
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return FLOAT_TYPE;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return DOUBLE_TYPE;
	if (checkInt(literal))
		return INT_TYPE;
	if (literal.back() == 'f' && checkDecimal(literal, 1))
		return FLOAT_TYPE;
	if (checkDecimal(literal, 0))
		return DOUBLE_TYPE;
	return NO_TYPE;
}

void	ScalarConverter::convert(std::string str) {
	LiteralType type = checkType(str);

	switch (type)
	{
		case NO_TYPE:
			std::cout << "Bad Type !" << std::endl;
			break;
		case CHAR_TYPE:
			convertChar(str);
			break;
		case INT_TYPE:
			convertInt(str);
			break;
		case FLOAT_TYPE:
			convertFloat(str);
			break;
		case DOUBLE_TYPE:
			convertDouble(str);
			break;
		default:
			break;
	}
}
/*	
    int	intValue;
    float	floatValue;
    double	doubleValue;

    if (sscanf(str.c_str(), "%d", &intValue) == 1) {
        std::cout << "Input is an int: " << intValue << std::endl;
    } else if (sscanf(str.c_str(), "%f", &floatValue) == 1) {
        std::cout << "Input is a float: " << floatValue << std::endl;
    } else if (sscanf(str.c_str(), "%lf", &doubleValue) == 1) {
        std::cout << "Input is a double: " << doubleValue << std::endl;
    } else {
        std::cout << "Input is a string: " << str << std::endl;
    }
}*/
