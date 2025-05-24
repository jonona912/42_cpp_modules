/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:46:57 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/24 11:29:22 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
	Fixed(void);
	Fixed(int const num);
	Fixed(float const fNum);
	~Fixed(void);
	Fixed(const Fixed& src); // copy constructor
	Fixed&	operator=(const Fixed& rhs); // copy assignment operator
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;
	bool	operator<(const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator>(const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;
	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	Fixed&	operator++(void); // pre-increment
	Fixed	operator++(int); // post-crement
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static Fixed&	max(Fixed &l, Fixed &r);
	static const Fixed& max(const Fixed &l, const Fixed &r);
	static Fixed& min(Fixed &l, Fixed &r);
	static const Fixed& min(const Fixed &l, const Fixed &r);
private:
	int					_fpNum;
	static int const	_fracBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);




#endif
