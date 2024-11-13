/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:30:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/20 12:26:50 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

std::string	uppercase(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			cout << uppercase(av[i]);
		cout << endl;
	}
	else if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return 0;
}
