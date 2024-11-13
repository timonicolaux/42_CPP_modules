/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:49:00 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/19 11:27:21 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T>

void	iter(const T* array, int length, void (*function)(const T& element))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
	return ;
};

template<typename T>

void	print(const T& element)
{
	std::cout << element << std::endl;
}

#endif
