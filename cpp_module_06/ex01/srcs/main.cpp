/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:21:13 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 17:29:21 by zkhojazo         ###   ########.fr       */
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

	return 0;
}
