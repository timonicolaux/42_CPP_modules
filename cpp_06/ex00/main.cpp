/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timonicolaux <timonicolaux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:03:43 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/19 17:55:14 by timonicolau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter one argument" << std::endl;
		return -1;
	}
	else
	{
		ScalarConverter::convert(av[1]);
		std::cout << std::endl;
	}
	return 0;
}
