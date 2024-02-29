/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:28:06 by sboetti           #+#    #+#             */
/*   Updated: 2024/02/29 18:39:24 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

enum LiteralType
{
	NO_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &cpy);
	ScalarConverter	&operator=(const ScalarConverter &rhs);
	~ScalarConverter();

	static LiteralType	checkType(std::string str);
	static bool	checkInt(std::string str);
	static bool	checkDecimal(std::string str);

	static void	convertChar(std::string str);
	static void	convertInt(std::string str);
	static void	convertFloat(std::string str);
	static void	convertDouble(std::string str);
public:
	static void	convert(std::string str);
};
