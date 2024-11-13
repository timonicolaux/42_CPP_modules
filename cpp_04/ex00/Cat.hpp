/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 08:37:27 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/11 09:31:21 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	private:
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat	&operator=(const Cat& src);
		void	makeSound() const;
};

#endif
