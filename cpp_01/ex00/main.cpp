/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:11:35 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/25 08:37:59 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string input;

	std::cout << "Name the Stack Zombie : ";
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		std::cout << "\nInput error. Program terminated." << std::endl;
		std::cin.clear();
		return -1;
	}
	randomChump(input);
	std::cout << "Name the Heap Zombie : ";
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		std::cout << "\nInput error. Program terminated." << std::endl;
		std::cin.clear();
		return -1;
	}
	Zombie*	zombie = newZombie(input);
	if (!zombie)
		return (-1);
	zombie->announce();
	delete zombie;
	return 0;
}
