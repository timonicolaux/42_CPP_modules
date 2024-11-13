/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:50:40 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/12 09:26:39 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() : _int(0)
{
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	return ;
}

Fixed::Fixed(const int num)
{
	this->_int = num << this->_bits;
	return ;
}
Fixed::Fixed(const float num)
{
	this->_int = roundf(num * (1 << this->_bits));
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_int = src.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_int++;
	return *this;
}

Fixed	Fixed::operator--()
{
	this->_int--;
	return *this;
}

Fixed	Fixed::operator++(int value)
{
	Fixed	tmp;
	tmp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return tmp;
}

Fixed	Fixed::operator--(int value)
{
	Fixed	tmp;
	tmp = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return tmp;
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return first;
	else
		return second;
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return first;
	else
		return second;
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return first;
	else
		return second;
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return first;
	else
		return second;
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
	return o;
}

