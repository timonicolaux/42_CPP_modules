/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:00:07 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 09:54:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constructor called for WrongCat" << std::endl;
	type = "WrongCat";
	return ;
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "Copy constructor called for WrongCat" << std::endl;
	*this = copy;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat& src)
{
	if (this == &src)
		return *this;
	else
		WrongAnimal::operator=(src);
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
	return ;
}

std::string	WrongCat::getType() const
{
	std::cout << type << std::endl;
	return type;
}
