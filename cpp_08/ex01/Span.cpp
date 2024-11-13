/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:35:14 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/25 13:42:43 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{}

Span	&Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_array = src._array;
	}
	return *this;
}

const char*	Span::ArrayIsFull::what() const throw()
{
	return "Array has reached maximum of N";
}

const char*	Span::ArrayIsTooSmall::what() const throw()
{
	return "Array is too small, it must contain at least two numbers";
}

const char*	Span::NotEnoughSpace::what() const throw()
{
	return "Too many numbers, can't add because array will unreach maximum of N";
}

void	Span::addNumber(int number)
{
	if (_array.size() == _N)
		throw Span::ArrayIsFull();
	else
	{
		_array.push_back(number);
		std::cout << "Number " << number << " added !" << std::endl;
	}
}

void	Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	if (std::distance(begin, end) + _array.size() > _N)
		throw Span::NotEnoughSpace();
	else
		_array.insert(_array.end(), begin, end);
}

unsigned int	Span::shortestSpan()
{
	int	(*pabs)(int) = &std::abs;
	if (_array.size() < 2)
		throw Span::ArrayIsTooSmall();
	std::vector<int>	temp = _array;
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
	std::transform(temp.begin(), temp.end(), temp.begin(), pabs);
	return *min_element(temp.begin(), temp.end());
}

unsigned int	Span::longestSpan()
{
	int	(*pabs)(int) = &std::abs;
	if (_array.size() < 2)
		throw Span::ArrayIsTooSmall();
	std::vector<int>	temp = _array;
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
	std::transform(temp.begin(), temp.end(), temp.begin(), pabs);
	return *max_element(temp.begin(), temp.end());
}
