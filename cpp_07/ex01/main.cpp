/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:16:45 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/27 12:44:02 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int	main()
{
	int	array[] = {1,2,3,4,5};

	int	length = sizeof(array) / sizeof(array[0]);
	iter(array, length, print);
	return 0;
}
