/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:12:50 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/21 08:59:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*new_zombie = new Zombie;
	if (!new_zombie)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return NULL;
	}
	new_zombie->setName(name);
	return new_zombie;
}
