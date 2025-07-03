/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:21:13 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/07 12:26:05 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"


int main() {

	Data data("Hello, World!");
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: " << *deserializedData << std::endl;

	char* charPtr = new char;
	uintptr_t invalidRaw = reinterpret_cast<uintptr_t>(charPtr);
	Data* invalidData = Serializer::deserialize(invalidRaw);
	std::cout << "Deserialized invalid data: " << invalidData << std::endl;
	
	
	// ...use invalidRaw...
	delete charPtr; // Clean up the allocated memory
	return 0;
}
