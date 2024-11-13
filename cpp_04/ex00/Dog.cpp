/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:17:47 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 09:54:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor called for Dog" << std::endl;
	type = "Dog";
	return ;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	*this = copy;
	return ;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog& src)
{
	if (this == &src)
		return *this;
	else
		Animal::operator=(src);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wooooof wooof" << std::endl;
	return ;
}
