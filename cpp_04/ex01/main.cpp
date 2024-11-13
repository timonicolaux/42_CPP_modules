/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:47:55 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 14:04:04 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	checkDeepCopy(Cat const& a)
{
	Cat tmp = a;
}

int	main()
{
	Cat	basic;

	if (basic.memoryError)
		return (-1);
	else
	{
		checkDeepCopy(basic);
		basic.makeSound();
	}

	Animal	*animalArray[20];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			animalArray[i] = new Dog;
			if (!animalArray[i] && i != 0)
			{
				for (int j = 0; j < i; j++)
					delete animalArray[j];
				return -1;
			}
		}
		else
		{
			animalArray[i] = new Cat;
			if (!animalArray[i])
			{
				for (int k = 0; k < i; k++)
					delete animalArray[k];
				return -1;
			}
		}
	}
	animalArray[8]->addBrainIdea(2, "Dog idea");
	animalArray[11]->addBrainIdea(2, "Cat idea");
	for (int i = 0; i < 20; i++)
		delete animalArray[i];

	return 0;
}



