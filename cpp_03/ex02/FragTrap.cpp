/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:27:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/09 10:49:38 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap constructor called, " << name << " created" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	return ;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor for " << name << " created" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called, " << name << " created" << std::endl;
	*this = copy;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor called, " << name << " destroyed" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		std::cout << "FragTrap Assignation Operator called" << std::endl;
		name = src.name;
		hit_points = src.hit_points;
		energy_points = src.energy_points;
		attack_damage = src.attack_damage;
	}
	return *this;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "High five !" << std::endl;
	return ;
}
