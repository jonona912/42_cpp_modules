/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:56:41 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 14:12:56 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : _n(1) {
	this->_arr = new T[this->_n];
}

template <typename T>
Array<T>::Array(unsigned int const &n) : _n(n) {
	this->_arr = new T[this->_n];
}

template <typename T>
Array<T>::~Array() {
	delete [] this->_arr;
	// std::cout << "Destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &other) : _n(other._n) {
	this->_arr = new T[other._n];
	for (unsigned int i = 0; i < this->_n; i++) {
		this->_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other) {
	
	if (this != &other) {
		delete [] this->_arr;
		this->_n = other._n;
		this->_arr = new T[this->_n];
		for (unsigned int i = 0; i < this->_n; i++) {
			this->_arr[i] = other._arr[i];
		}
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_n;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _n)
		throw OutOfBoundsException();
	return this->_arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_n)
		throw OutOfBoundsException();
	return this->_arr[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return "Out of bounds";
}
