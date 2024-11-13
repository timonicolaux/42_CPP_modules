/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:05 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 14:03:47 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : memoryError(false)
{
	std::cout << "Default constructor called for Dog" << std::endl;
	type = "Dog";
	brain = new Brain;
	if (!brain)
	{
		std::cout << "Memory allocation failed" << std::endl;
		memoryError = true;
	}
	return ;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	this->brain = new Brain(*copy.brain);
	if (!brain)
	{
		std::cout << "Memory allocation failed" << std::endl;
		memoryError = true;
	}
	return ;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;
	delete brain;
	return ;
}

Dog	&Dog::operator=(const Dog& src)
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

void	Dog::makeSound() const
{
	std::cout << "Wooooof wooof" << std::endl;
	return ;
}

void	Dog::addBrainIdea(int index, const std::string idea)
{
	std::cout << "Adding idea to Dog brain..." << std::endl;
	this->brain->addIdea(index, idea);
	return ;
}
