/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:13:04 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/24 15:33:33 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon	&_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};

#endif
