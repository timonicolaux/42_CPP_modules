/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:20:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/19 15:48:54 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	return 0;
}
