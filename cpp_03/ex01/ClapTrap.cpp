/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:19:32 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/17 08:52:23 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("No name"), hit_points(100), energy_points(50), attack_damage(20)
{
	std::cout << "Default constructor called, Claptrap " << name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor for " << name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor called, " << name << " created" << std::endl;
	*this = copy;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap default destructor called, " << name << " destroyed" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& src)
{
	if (this != &src)
	{
		std::cout << "ClapTrap Assignation Operator called" << std::endl;
		name = src.name;
		hit_points = src.hit_points;
		energy_points = src.energy_points;
		attack_damage = src.attack_damage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energy_points <= 0)
		std::cout << "No energy points left for " << name << " !" << std::endl;
	else if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return ;
	}
	else if (attack_damage < 0)
		std::cout << "Attack damage can not be negative" << std::endl;
	else if (attack_damage >= 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage !" << std::endl;
		energy_points--;
		hit_points -= attack_damage;
	}
	if (hit_points < 0)
		hit_points = 0;
	if (!hit_points)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		std::cout << "No amount" << std::endl;
	else if (amount < 0)
		std::cout << "Amount must be positive" << std::endl;
	else if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return ;
	}
	else
		hit_points -= (int)amount;
	if (hit_points < 0)
		hit_points = 0;
	if (!hit_points)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0)
		std::cout << "No energy points left for " << name << " !" << std::endl;
	else if (amount == 0)
		std::cout << "No amount" << std::endl;
	else if (amount < 0)
		std::cout << "Amount must be positive" << std::endl;
	else
	{
		std::cout << "ClapTrap has gained " << amount << " hit points" << std::endl;
		hit_points += (int)amount;
		energy_points--;
	}
	return ;
}

void	ClapTrap::set_damage(int amount)
{
	if (amount < 0)
		std::cout << "Please set a positive value" << std::endl;
	else
	{
		std::cout << "Attack damage set to " << amount << " for " << name << std::endl;
		attack_damage = amount;
	}
}

void	ClapTrap::set_energy(int amount)
{
	if (amount < 0)
		std::cout << "Please set a positive value" << std::endl;
	else
	{
		std::cout << "Energy points set to " << amount << " for " << name << std::endl;
		energy_points = amount;
	}
}

void	ClapTrap::set_hit_points(int amount)
{
	if (amount < 0)
		std::cout << "Please set a positive value" << std::endl;
	else
	{
		std::cout << "Hit points set to " << amount << " for " << name << std::endl;
		hit_points = amount;
	}
}
