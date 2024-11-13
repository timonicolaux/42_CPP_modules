/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:34 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/16 14:23:21 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called, " << name << " created" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor for " << name << " created" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called, " << name << " created" << std::endl;
	*this = copy;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default destructor called, " << name << " destroyed" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
	{
		std::cout << "ScavTrap Assignation Operator called" << std::endl;
		name = src.name;
		hit_points = src.hit_points;
		energy_points = src.energy_points;
		attack_damage = src.attack_damage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energy_points <= 0)
		std::cout << "No energy points left !" << std::endl;
	else if (hit_points == 0)
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
	else if (attack_damage < 0)
		std::cout << "Please set a positive value to attack damage" << std::endl;
	else if (attack_damage >= 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage !" << std::endl;
		energy_points--;
		hit_points -= attack_damage;
	}
	if (hit_points < 0)
		hit_points = 0;
	return ;
}

void	ScavTrap::guardGate()
{
	if (!gate_keeper_mode)
	{
		gate_keeper_mode = true;
		std::cout << "ScavTrap " << name << " is now in gate keeper mode" << std::endl;
	}
	else
	{
		gate_keeper_mode = false;
		std::cout << "ScavTrap " << name << " isn't in gate keeper mode anymore" << std::endl;
	}
	return ;
}
