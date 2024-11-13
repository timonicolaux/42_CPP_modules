/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:34:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 10:24:50 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Please enter one string of calculation (ex: \"5 4 +\")" << std::endl;
		return -1;
	}
	RPN	myClass(av[1]);
	return 0;
}
