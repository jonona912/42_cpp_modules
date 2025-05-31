/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:13:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/31 17:23:23 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

class Data;

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
