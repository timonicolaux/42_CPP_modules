/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:27:45 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 11:36:35 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called for Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty idea";
	return ;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = copy;
	return ;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain" << std::endl;
	return ;
}

Brain	&Brain::operator=(const Brain& src)
{
	if (this == &src)
		return *this;
	return *this;
}

void	Brain::addIdea(int index, const std::string idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
		std::cout << "Idea added to brain : " << ideas[index] << std::endl;
	}
	else
		std::cout << "Index must be situated between 0 and 99" << std::endl;
	return ;
}
