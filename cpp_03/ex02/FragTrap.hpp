/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:28:14 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/09 11:17:23 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
		FragTrap	&operator=(const FragTrap& src);
		void	highFiveGuys(void);
};

#endif
