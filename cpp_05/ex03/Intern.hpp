/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:25:53 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/13 13:02:36 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class	Intern
{
	private:
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern	&operator=(const Intern& src);
		AForm *makeForm(const std::string name, const std::string form);
		AForm	*newPresidentialPardonForm(const std::string target);
		AForm	*newRobotomyRequestForm(const std::string target);
		AForm	*newShrubberyCreationForm(const std::string target);
};

#endif
