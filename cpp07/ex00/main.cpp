/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:28:22 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/27 09:30:37 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	int a = 15;
	int b = 4;

	std::cout << "BEFORE SWAP -> a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "AFTER SWAP -> a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "BEFORE SWAP -> c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "AFTER SWAP -> c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
