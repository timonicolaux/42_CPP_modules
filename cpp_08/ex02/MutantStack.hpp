/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:16:12 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/26 10:24:05 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template<typename T>

class	MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();
		MutantStack	&operator=(const MutantStack& src);
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
