/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:17:46 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/25 13:41:41 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	//Tests with basic addNumber() function

	Span	A(5);

	for (int i = 0; i < 10; i++)
	{
		try
		{
			if (i == 0)
				A.addNumber(6);
			else if (i == 1)
				A.addNumber(3);
			else if (i == 2)
				A.addNumber(17);
			else if (i == 3)
				A.addNumber(9);
			else if (i == 4)
				A.addNumber(11);
			else
				A.addNumber(150);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	try
	{
		unsigned int	shortest = A.shortestSpan();
		std::cout << "Shortest Span : " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		unsigned int	longest = A.longestSpan();
		std::cout << "Longest Span : " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	//Tests with improved addNumber() function

	Span	B(10000);

	std::vector<int>	array;
	for (int i = 0; i < 10000; i++)
		array.push_back(i);

	try
	{
		B.addNumber(array.begin(), array.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		unsigned int	shortest = B.shortestSpan();
		std::cout << "Shortest Span : " << shortest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		unsigned int	longest = B.longestSpan();
		std::cout << "Longest Span : " << longest << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
