/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:09:55 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/08 13:52:09 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		bool	gate_keeper_mode;
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& copy);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap& src);
		void	attack(const std::string& target);
		void	guardGate();
};
#endif
