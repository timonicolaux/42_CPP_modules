/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:57:09 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/22 12:51:57 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>

void	swap(T& arg1, T& arg2)
{
	T arg_cpy = arg1;

	arg1 = arg2;
	arg2 = arg_cpy;
	return ;
};
template<typename T>

T	min(T& arg1, T& arg2)
{
	if (arg2 <= arg1)
		return arg2;
	return arg1;
};
template<typename T>

T	max(T& arg1, T& arg2)
{
	if (arg2 >= arg1)
		return arg2;
	return arg1;
};

#endif
