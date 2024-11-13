/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:00 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 13:42:43 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain*	brain;
	public:
		bool	memoryError;
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog	&operator=(const Dog& src);
		void	makeSound() const;
		void	addBrainIdea(int index, const std::string idea);
};

#endif
