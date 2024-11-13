/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:17 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 14:13:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		bool	memoryError;
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal	&operator=(const Animal& src);
		virtual void	makeSound() const = 0;
		std::string	getType() const;
		virtual void	addBrainIdea(int index, const std::string idea) = 0;
};

#endif
