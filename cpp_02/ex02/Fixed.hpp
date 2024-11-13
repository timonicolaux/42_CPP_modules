/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:50:38 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/12 09:26:46 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int	_int;
		static const int _bits;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		bool	operator>(Fixed fixed) const;
		bool	operator<(Fixed fixed) const;
		bool	operator>=(Fixed fixed) const;
		bool	operator<=(Fixed fixed) const;
		bool	operator==(Fixed fixed) const;
		bool	operator!=(Fixed fixed) const;
		float	operator+(Fixed fixed) const;
		float	operator-(Fixed fixed) const;
		float	operator*(Fixed fixed) const;
		float	operator/(Fixed fixed) const;
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int value);
		Fixed	operator--(int value);
		static	Fixed &min(Fixed &first, Fixed &second);
		static const	Fixed &min(Fixed const &first, Fixed const &second);
		static	Fixed &max(Fixed &first, Fixed &second);
		static const	Fixed &max(Fixed const &first, Fixed const &second);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);


#endif
