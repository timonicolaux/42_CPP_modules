/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:58:20 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/25 14:54:58 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	main()
{
	Harl	harl;
	std::string	input;

	while (42)
	{
		std::cout << "\nComplains available : DEBUG - INFO - WARNING - ERROR\n" << std::endl;
		std::cout << "Enter your complain level : ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			std::cout << "Input error. Program terminated." << std::endl;
			return -1;
		}
		std::cout << std::endl;
		harl.complain(input);
	}
	return 0;
}
