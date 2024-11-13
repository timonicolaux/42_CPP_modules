/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:17:16 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/22 09:14:05 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	animalSound(Animal const& a)
{
	a.makeSound();
	a.getType();
}

int	main()
{
	Animal	a;

	animalSound(a);

	Dog	b;

	animalSound(b);

	Cat	c;

	animalSound(c);

	WrongAnimal* meta = new WrongAnimal();
	Animal* j = new Dog();
	WrongAnimal* i = new WrongCat();
	j->getType();
	i->getType();
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}



