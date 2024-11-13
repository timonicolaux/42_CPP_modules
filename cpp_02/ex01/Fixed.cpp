/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:50:40 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/26 14:26:33 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() : _int(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_int = num << this->_bits;
	return ;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_int = roundf(num * (1 << this->_bits));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		this->_int = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_int;
}

void	Fixed::setRawBits(int const raw)
{
	this->_int = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_int / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_int >> this->_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

