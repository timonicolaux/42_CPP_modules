/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:11:28 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/08 13:30:10 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	protected:
		std::string	name;
		int	hit_points;
		int	energy_points;
		int	attack_damage;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap& src);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	set_damage(int amount);
		void	set_energy(int amount);
		void	set_hit_points(int amount);
};

#endif
