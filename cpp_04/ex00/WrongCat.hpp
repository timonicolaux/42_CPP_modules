/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:00:24 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/11 10:40:02 by tnicolau         ###   ########.fr       */
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
