/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:30 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/19 08:58:29 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	private:
		std::string	type;
	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		~WrongCat();
		WrongCat &operator=(const WrongCat& src);
		void	makeSound() const;
		std::string	getType() const;
};

#endif
