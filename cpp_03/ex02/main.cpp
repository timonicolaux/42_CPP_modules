/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:20:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/17 08:53:26 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "\n/// ClapTrap tests ///\n" << std::endl;
	ClapTrap	a;
	ClapTrap	b("Max");

	for (int i = 0; i < 5; i++)
		a.attack("Max");

	std::cout << "\n/// ScavTrap tests ///\n" << std::endl;
	ScavTrap	c;
	ScavTrap	d("John");

	for (int i = 0; i < 5; i++)
		c.attack("John");
	c.guardGate();
	c.guardGate();

	std::cout << "\n/// FragTrap tests ///\n" << std::endl;
	FragTrap	e;
	FragTrap	f("Bob");

	e.highFiveGuys();
	f.highFiveGuys();
	return 0;
}
