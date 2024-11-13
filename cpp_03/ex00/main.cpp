/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:20:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/17 08:53:02 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("Max");

	for (int i = 0; i < 11; i++)
		a.attack("Bob");
	a.set_energy(10);
	for (int i = 0; i < 11; i++)
		a.takeDamage(2);
	a.set_energy(1);
	a.beRepaired(10);
	return 0;
}
