/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:53:18 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/20 09:53:19 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
	int	num;
	std::string	str;
};

class	Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
	public:
		~Serializer();
		Serializer	&operator=(const Serializer &src);
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif
