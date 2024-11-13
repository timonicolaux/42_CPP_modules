/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:15:59 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/25 14:14:34 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>

MutantStack<T>::MutantStack() : std::stack<T>()
{}

template<typename T>

MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy)
{
	*this = copy;
}

template<typename T>

MutantStack<T>::~MutantStack()
{}

template<typename T>

MutantStack<T>	&MutantStack<T>::operator=(const MutantStack& src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template<typename T>

typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>

typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>

typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>

typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return this->c.end();
}
