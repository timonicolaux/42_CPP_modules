/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:28:39 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 09:54:30 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor called for Cat" << std::endl;
	type = "Cat";
	return ;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	*this = copy;
	return ;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat& src)
{
	if (this == &src)
		return *this;
	else
		Animal::operator=(src);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miiaaaaouuwwww miaaaawwww" << std::endl;
	return ;
}
