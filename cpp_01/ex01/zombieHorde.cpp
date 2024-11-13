/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:17:31 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/21 08:58:23 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

std::string intToString(int value)
{
	std::ostringstream	oss;
	oss << value;
	return oss.str();
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cout << "There must be at least one zombie" << std::endl;
		return NULL;
	}
	Zombie	*zombie_hord = new Zombie[N];
	if (!zombie_hord)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++)
		zombie_hord[i].setName(name + " " + intToString(i));
	return zombie_hord;
}
