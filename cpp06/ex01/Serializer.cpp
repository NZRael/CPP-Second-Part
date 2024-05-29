/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:42:20 by sboetti           #+#    #+#             */
/*   Updated: 2024/05/28 13:41:48 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &cpy){
	*this = cpy;
}

Serializer	&Serializer::operator=(const Serializer &rhs){
	if (this == &rhs)
		return (*this);
	return (*this);
}

Serializer::~Serializer(){}

uintptr_t	Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}
