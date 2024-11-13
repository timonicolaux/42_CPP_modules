/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:50 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/19 09:01:07 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
	type = "WrongAnimal";
	return ;
}
WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
	*this = copy;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this == &src)
		return *this;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
	return ;
}

std::string	WrongAnimal::getType() const
{
	std::cout << type << std::endl;
	return type;
}

