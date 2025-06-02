/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:22:34 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/06/01 14:22:34 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

// template <typename T, typename Func>
// void iter(T arr[], size_t len, Func func) {
//     for (size_t i = 0; i < len; ++i) {
//         func(arr[i]);
//     }
// }

template <typename T>
void iter(T arr[], size_t len, void (*func)(T &arg)) {
	for (size_t i = 0; i < len; ++i) {
		func(arr[i]);
	}
}

template <typename T>
void iter(T arr[], size_t len, void (*func)(T const &arg)) {
	for (size_t i = 0; i < len; ++i) {
		func(arr[i]);
	}
}

