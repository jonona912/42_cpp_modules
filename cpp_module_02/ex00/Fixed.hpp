/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:46:57 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/22 13:46:58 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& src); // copy constructor
	Fixed& operator=(const Fixed& rhs);//  copy assignment operator
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int _fpNum;
	static int const _fracBits;
};


#endif