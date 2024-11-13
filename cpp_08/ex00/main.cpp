/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:49:24 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/26 10:56:37 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int>	array;
	array.push_back(1);
	array.push_back(1);
	array.push_back(3);
	array.push_back(4);
	array.push_back(2);

	int	to_find = 2;
	int	result = easyfind(array, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array" << std::endl;

	to_find = 8;
	result = easyfind(array, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array" << std::endl;

	std::list<int>	array2;
	array2.push_back(1);
	array2.push_back(1);
	array2.push_back(3);
	array2.push_back(4);
	array2.push_back(2);

	to_find = 2;
	result = easyfind(array2, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array2" << std::endl;

	to_find = 8;
	result = easyfind(array2, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array2" << std::endl;

	std::deque<int>	array3;
	array3.push_back(1);
	array3.push_back(1);
	array3.push_back(3);
	array3.push_back(4);
	array3.push_back(2);

	to_find = 2;
	result = easyfind(array3, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array3" << std::endl;

	to_find = 8;
	result = easyfind(array3, to_find);
	if (result != -1)
		std::cout << "Number " << to_find << " found at index " << result << std::endl;
	else
		std::cout << "Number " << to_find << " not found in array3" << std::endl;
	return 0;
}
