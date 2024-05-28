/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:22:45 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/27 13:12:49 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t length, F func){
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}


template<typename T>
void	doubleValue(T& value) {
	value *= 2;
}

template <typename T>
void	addOne(T& value) {
	value += 1;
}
