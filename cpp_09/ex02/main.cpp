/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:24 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 13:29:56 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Please include at least one number" << std::endl;
		return -1;
	}

	std::string	input;

	for (int i = 1; i < ac; ++i)
	{
		input += av[i];
		if (i < ac - 1)
			input += 32;
	}
	for (int j = 0; j < (int)input.length(); ++j)
	{
		if ((input[j] < 48 || input[j] > 57) && input[j] != 32)
		{
			std::cerr << "Error: input must be only positive integers" << std::endl;
			return -1;
		}
	}

	try
	{
		PmergeMe	myClass(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
