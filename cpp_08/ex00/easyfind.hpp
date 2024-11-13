/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:48:12 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/26 10:56:47 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template<typename T>

int	easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		return -1;
	return std::distance(container.begin(), it);
}

#endif
