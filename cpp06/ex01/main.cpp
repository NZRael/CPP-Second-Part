/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:43:18 by sboetti           #+#    #+#             */
/*   Updated: 2024/03/11 16:12:26 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	// Création d'un objet de données
	Data originalData;
	originalData.name = "Hello";
	originalData.i = 42;

	// Sérialisation de l'objet de données
	unsigned long serializedPtr = Serializer::serialize(&originalData);
	std::cout << "Address of originalData: " << &originalData << std::endl;
	std::cout << "Serialized pointer value: " << serializedPtr << std::endl;

	// Désérialisation du pointeur
	Data* deserializedData = Serializer::deserialize(serializedPtr);
	std::cout << "Deserialized pointer value: " << deserializedData << std::endl;

	// Comparaison des pointeurs
	if (deserializedData == &originalData) {
		std::cout << "Pointers are equal. Serialization and deserialization are successful." << std::endl;
	} else {
		std::cout << "Pointers are not equal. Serialization and deserialization failed." << std::endl;
	}

 	// Test de modification de l'objet original après la sérialisation
	originalData.i = 100;

	std::cout << std::endl << "Modified Original Data Address: " << &originalData << std::endl;

	// Nouvelle comparaison des pointeurs
	if (deserializedData == &originalData) {
		std::cout << "Pointers are equal. Serialization and deserialization are successful." << std::endl;
	} else {
		std::cout << "Pointers are not equal. Serialization and deserialization failed." << std::endl;
	}

	// Création d'un nouvel objet de données
	Data newData;
	newData.name = "World";
	newData.i = 99;

	// Sérialisation du nouvel objet de données
	unsigned long serializedPtrNew = Serializer::serialize(&newData);
	std::cout << std::endl << "Address of newData: " << &newData << std::endl;
	std::cout << "Serialized pointer value for newData: " << serializedPtrNew << std::endl;

	// Désérialisation du pointeur pour le nouvel objet de données
	Data* deserializedDataNew = Serializer::deserialize(serializedPtrNew);
	std::cout << "Deserialized pointer value for newData: " << deserializedDataNew << std::endl;

	// Comparaison des pointeurs pour le nouvel objet de données
	if (deserializedDataNew == &newData) {
		std::cout << "Pointers are equal for newData. Serialization and deserialization are successful." << std::endl;
	} else {
		std::cout << "Pointers are not equal for newData. Serialization and deserialization failed." << std::endl;
	}

	return 0;
}
