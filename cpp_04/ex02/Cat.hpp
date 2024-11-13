/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:48:09 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 13:45:21 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		bool	memoryError;
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat	&operator=(const Cat& src);
		void	makeSound() const;
		void	addBrainIdea(int index, const std::string idea);
};

#endif
