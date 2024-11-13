/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:44 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/19 09:00:40 by tnicolau         ###   ########.fr       */
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
