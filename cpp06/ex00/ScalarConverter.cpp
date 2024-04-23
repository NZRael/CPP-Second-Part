/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:28:08 by sboetti           #+#    #+#             */
/*   Updated: 2024/04/23 13:50:03 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/////////////////////// CONSTRUCTION ////////////////////

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

//////////////// CONVERSION ///////////////////////

void	ScalarConverter::convertChar(const std::string &str){
	char	c = str[0];

	printChar(c);
	printInt(static_cast<int>(str[0]));
	printFloat(static_cast<float>(str[0]));
	printDouble(static_cast<double>(str[0]));
}

void	ScalarConverter::printChar(char c){
	if (std::isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else if (c > 127 || c < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::convertInt(const std::string &str){
	char* endPtr;
	long	test = std::strtol(str.c_str(), &endPtr, 10);
	int		i = static_cast<int>(test);

	if (test < 0 || test > 127) {
		std::cout << "char: impossible" << std::endl;
	}
	else
		printChar(static_cast<char>(i));
	if (test < std::numeric_limits<int>::min() || test > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	}
	else
		printInt(i);
	if (test < std::numeric_limits<int>::min() || test > std::numeric_limits<int>::max()) {
		std::cout << "float: impossible" << std::endl;
	}
	else
		printFloat(static_cast<float>(i));
	if (test < std::numeric_limits<int>::min() || test > std::numeric_limits<int>::max()) {
		std::cout << "double: impossible" << std::endl;
	}
	else
		printDouble(static_cast<double>(i));
}

void	ScalarConverter::printInt(int i){
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::convertFloat(const std::string &str){
	double	d = std::atof(str.c_str());
	float	f = static_cast<float>(d);

	if (f < 0 || f > 127) {
		std::cout << "char: impossible" << std::endl;
	}
	else
		printChar(static_cast<char>(f));
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		printInt(static_cast<int>(f));
	printFloat(f);
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "double: impossible" << std::endl;
	else
		printDouble(static_cast<double>(f));
}

void	ScalarConverter::printFloat(float f){
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	ScalarConverter::convertDouble(const std::string &str){
	char	*endPTR;
	double	d = std::strtod(str.c_str(), &endPTR);

	if (d < 0 || d > 127) {
		std::cout << "char: impossible" << std::endl;
	}
	else
		printChar(static_cast<char>(d));
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		printInt(static_cast<int>(d));
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		printFloat(static_cast<float>(d));
	printDouble(d);
}

void	ScalarConverter::printDouble(double d){
	if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::ft_nan(const std::string &str){
	std::cout << "char: impossible" << std:: endl
		<< "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
		std::cout << "float: nanf" << std::endl
		<< "double: nan" << std::endl;
	else if (str == "+inf" || str == "+inff")
		std::cout << "float: inff" << std::endl
		<< "double: inf" << std::endl;
	else if (str == "-inf" || str == "-inff")
        std::cout << "float: -inff" << std::endl
		<< "double: -inf" << std::endl;
}

bool	ScalarConverter::checkInt(const std::string &str){
	size_t start;
	if (str[0] == '-' || str[0] == '+')
		start = 1;
	else
		start = 0;
	for (size_t i = start; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::checkDecimal(const std::string &str, int end){
	size_t	pos = 0;
	size_t	count = 0;
	size_t	start;

	if (str[0] == '-' || str[0] == '+')
		start = 1;
	else
		start = 0;
	for (size_t i = start; i < str.length() - end; i++){
		if (str[i] == '.'){
			pos = i;
			count++;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	if (count == 0 && end == 0)
		return false;
	if (count == 1 && end == 1 && pos != (str.length() - end - 1))
		return true;
	if (count > 1 && end == 1)
		return false;
	if (count == 1 && pos == (str.length() - end - 1))
		return false;
	return true;
}

Strtype	ScalarConverter::checkType(const std::string &str){
	if (str.empty())
		return NO_TYPE;
	if (str.length() == 1 && std::isalpha(str[0]))
		return CHAR_TYPE;
	if (str == "-inff" || str == "+inff" || str == "nanf"
	|| str == "-inf" || str == "+inf" || str == "nan")
		return NAN_TYPE;
	if (checkInt(str))
		return INT_TYPE;
	if (str[str.length() - 1] == 'f' && checkDecimal(str, 1))
		return FLOAT_TYPE;
	if (checkDecimal(str, 0))
		return DOUBLE_TYPE;
	return NO_TYPE;
}

void	ScalarConverter::convert(const std::string &str) {
	Strtype type = checkType(str);

	switch (type)
	{
		case NO_TYPE:
			std::cout << "char: impossible" << std::endl << "int: impossible"
			<< std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
			break;
		case NAN_TYPE:
			ft_nan(str);
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
