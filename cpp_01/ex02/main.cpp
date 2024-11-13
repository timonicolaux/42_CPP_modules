/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:09:37 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/21 11:06:29 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of str : " << &str << std::endl;
	std::cout << "Address of str pointer : " << stringPTR << std::endl;
	std::cout << "Address of str reference : " << &stringREF << std::endl;

	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value of str pointer : " << *stringPTR << std::endl;
	std::cout << "Value of str reference : " << stringREF << std::endl;
	return 0;
}
