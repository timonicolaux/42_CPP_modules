/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:53:12 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/20 09:53:13 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called for Serializer" << std::endl;
}

Serializer::Serializer(const Serializer& copy)
{
	std::cout << "Copy constructor called for Serializer" << std::endl;
	*this = copy;
}

Serializer::~Serializer()
{
	std::cout << "Default destructor called for Serializer" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer& src)
{
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
