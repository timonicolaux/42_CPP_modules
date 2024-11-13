/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:48:01 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/27 10:05:01 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>

Array<T>::Array() : array(new T[0]), array_size(0)
{
	std::cout << "Array default constructor called" << std::endl;
	return ;
}

template<typename T>

Array<T>::Array(const Array& copy)
{
	std::cout << "Array copy constructor called" << std::endl;
	this->array = new T[copy.array_size];
	this->array_size = copy.array_size;
	for (unsigned int i = 0; i < copy.array_size; i++)
		this->array[i] = copy.array[i];
	return ;
}

template<typename T>

Array<T>::Array(unsigned int n) : array(new T[n]), array_size(n)
{
	std::cout << "Array unsigned int constructor called" << std::endl;
	for (unsigned int i = 0; i < n; i++)
		this->array[i] = 0;
	return ;
}

template<typename T>

Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[] this->array;
	return ;
}

template<typename T>

Array<T>	&Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		delete[] this->array;
		this->array = new T[src.array_size];
		this->array_size = src.array_size;
		for (unsigned int i = 0; i < src.array_size; i++)
			this->array[i] = src.array[i];
	}
	return *this;
}

template<typename T>

unsigned int	Array<T>::size() const
{
	return this->array_size;
}

template<typename T>

const char*	Array<T>::IndexOutOfBounds::what() const throw()
{
	return "Index out of bounds !";
}

template<typename T>

T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->array_size)
		throw Array<T>::IndexOutOfBounds();
	return this->array[index];
}
