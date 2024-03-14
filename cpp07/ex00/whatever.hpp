/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:28:21 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/14 10:37:12 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T>
void	swap(T &x, T &y){
	T	tmp = x;
	x = y;
	y = tmp;
}

template < typename T>
T const &	min(T const & x, T const & y){
	if (x == y)
		return y;
	return ( (x <= y) ? x : y);
}

template < typename T>
T const &	max(T const & x, T const & y){
	if (x == y)
		return y;
	return ( (x >= y) ? x : y);
}
