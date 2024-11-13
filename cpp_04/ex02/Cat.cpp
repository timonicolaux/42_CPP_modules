/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:13 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 14:04:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : memoryError(false)
{
	std::cout << "Default constructor called for Cat" << std::endl;
	type = "Cat";
	brain = new Brain;
	if (!brain)
	{
		std::cout << "Memory allocation failed" << std::endl;
		memoryError = true;
	}
	return ;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	this->brain = new Brain(*copy.brain);
	if (!brain)
	{
		std::cout << "Memory allocation failed" << std::endl;
		memoryError = true;
	}
	return ;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
	delete brain;
	return ;
}

Cat	&Cat::operator=(const Cat& src)
{
	if (this == &src)
		return *this;
	else
	{
		Animal::operator=(src);
		delete this->brain;
		this->brain = new Brain(*src.brain);
		if (!brain)
		{
			std::cout << "Memory allocation failed" << std::endl;
			memoryError = true;
		}
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miiaaaaouuwwww miaaaawwww" << std::endl;
	return ;
}

void	Cat::addBrainIdea(int index, const std::string idea)
{
	std::cout << "Adding idea to Cat brain..." << std::endl;
	this->brain->addIdea(index, idea);
	return ;
}
