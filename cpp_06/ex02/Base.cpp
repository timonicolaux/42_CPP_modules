/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:55:59 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/20 13:07:35 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	return ;
}

int	getRandomNumber()
{
	int	random_number;

	srand(time(0));
	random_number = rand() % 3;
	return random_number;
}

Base	*generate(void)
{
	int	random_number = getRandomNumber();

	if (random_number == 0)
	{
		A	*Aclass = new A();
		return Aclass;
	}
	else if (random_number == 1)
	{
		B	*Bclass = new B();
		return Bclass;
	}
	else if (random_number == 2)
	{
		C	*Cclass = new C();
		return Cclass;
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C pointer" << std::endl;
	else
		std::cout << "Wrong type" << std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A &tmp = dynamic_cast<A&>(p);
		(void)tmp;
		std::cout << "A reference" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &tmp = dynamic_cast<B&>(p);
			(void)tmp;
			std::cout << "B reference" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &tmp = dynamic_cast<C&>(p);
				(void)tmp;
				std::cout << "C reference" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	return ;
}
