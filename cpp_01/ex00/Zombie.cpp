/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:13:14 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/21 10:08:22 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
	return;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been shot down by a survivalist" << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	return;
}

