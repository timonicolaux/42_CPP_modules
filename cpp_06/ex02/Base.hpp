/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:56:13 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/20 11:35:02 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class	Base
{
	public:
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

#endif
