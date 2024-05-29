/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:14:59 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/28 12:02:59 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array{
private:
	T* elements;
	unsigned int _size;

public:
	Array() : _size(0) {
		elements = new T[_size];
	}

	Array(unsigned int n) : _size(n) {
		elements = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			elements[i] = T();
		}
	}

	Array(const Array& cpy) : _size(cpy._size) {
		elements = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			elements[i] = cpy.elements[i];
		}
	}

	Array& operator=(const Array& rhs) {
		if (this != &rhs) {
			delete[] elements;
			_size = rhs._size;
			elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) {
				elements[i] = rhs.elements[i];
			}
		}
		return *this;
	}

	~Array() {
		delete[] elements;
	}

	unsigned int	size() const{
		return (_size);
	}

	T& operator[](unsigned int index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return elements[index];
	}
};
