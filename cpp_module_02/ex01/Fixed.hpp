/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:46:57 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/22 21:23:20 by zkhojazo         ###   ########.fr       */
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
	Fixed&	operator=(const Fixed& rhs);//  copy assignment operator
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	int					_fpNum;
	static int const	_fracBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif