/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:13:17 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/25 11:38:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return;
}

Weapon::~Weapon()
{
	return;
}

const	std::string	&Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(const std::string type)
{
	this->_type = type;
	return;
}
