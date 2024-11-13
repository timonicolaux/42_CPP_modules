/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:49:55 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/19 08:59:24 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	private:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal& src);
		void	makeSound() const;
		std::string	getType() const;
};

#endif
