/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:18:04 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 09:55:11 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called for Animal" << std::endl;
	type = "Animal";
	return ;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Copy constructor called for Animal" << std::endl;
	*this = copy;
	return ;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal& src)
{
	if (this == &src)
		return *this;
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "WfanDFAAaaaaaarggghhhhh ! (Animal sound)" << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	std::cout << type << std::endl;
	return type;
}
