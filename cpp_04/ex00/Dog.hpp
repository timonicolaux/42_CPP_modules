/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:12:41 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/11 09:31:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	private:
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog	&operator=(const Dog& src);
		void	makeSound() const;
};

#endif
