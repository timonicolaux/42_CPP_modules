/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:18:13 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/17 14:34:24 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal	&operator=(const Animal& src);
		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif
