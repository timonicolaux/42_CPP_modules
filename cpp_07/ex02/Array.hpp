/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:00:36 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/27 10:03:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class	Array
{
	private:
		T	*array;
		unsigned int	array_size;
	public:
		Array();
		Array(const Array& copy);
		Array(unsigned int n);
		~Array();
		Array	&operator=(const Array& src);
		unsigned int size() const;
		T	&operator[](unsigned int index);
		class IndexOutOfBounds : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#include "Array.tpp"

#endif
