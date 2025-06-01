/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:56:57 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 14:13:02 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array {
	public:
		Array ();
		Array (unsigned int const &n);
		~Array();
		Array (Array const &other);
		Array& operator=(Array const &other);
		unsigned int size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		unsigned int	_n;
		T				*_arr;
};

#include "../srcs/Array.tpp"
