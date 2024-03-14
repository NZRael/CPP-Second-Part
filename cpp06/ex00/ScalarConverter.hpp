/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:28:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/04 17:42:32 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <limits>

enum Strtype
{
	NO_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	NAN_TYPE
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter	&operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	static Strtype	checkType(const std::string &str);
	static bool	checkInt(const std::string &str);
	static bool	checkDecimal(const std::string &str, int end);

	static void	convertChar(const std::string &str);
	static void	convertInt(const std::string &str);
	static void	convertFloat(const std::string &str);
	static void	convertDouble(const std::string &str);

	static void	printChar(char c);
	static void	printInt(int i);
	static void	printFloat(float f);
	static void	printDouble(double d);

	static void	ft_nan(const std::string &str);
public:
	static void	convert(const std::string &str);
};
