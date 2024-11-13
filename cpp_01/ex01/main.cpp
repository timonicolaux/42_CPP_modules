/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:11:35 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/21 10:07:18 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	std::string	input;
	int	converted_input(0);

	std::cout << "Enter the number of Zombies : ";
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		std::cout << "\nInput error. Program terminated." << std::endl;
		std::cin.clear();
		return -1;
	}
	converted_input = std::atoi(input.c_str());
	Zombie*	zombies = zombieHorde(converted_input, "Zombie hord member");
	if (!zombies)
		return (-1);
	for (int i = 0; i < converted_input; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
