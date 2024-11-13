/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:30:07 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/13 14:13:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called for Intern" << std::endl;
	return ;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
	*this = copy;
	return ;
}

Intern::~Intern()
{
	std::cout << "Default destructor called for Intern" << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern& src)
{
	if (this == &src)
		return *this;
	return *this;
}

AForm	*Intern::newPresidentialPardonForm(const std::string target)
{
	PresidentialPardonForm *form = new PresidentialPardonForm(target);
	if (form)
	{
		std::cout << "Intern created new PresidentialPardonForm" << std::endl;
		return (form);
	}
	else
		std::cout << "PresidentialPardonForm creation failed" << std::endl;
	return (NULL);
}

AForm	*Intern::newRobotomyRequestForm(const std::string target)
{
	RobotomyRequestForm *form = new RobotomyRequestForm(target);
	if (form)
	{
		std::cout << "Intern created new RobotomyRequestForm" << std::endl;
		return (form);
	}
	else
		std::cout << "RobotomyRequestForm creation failed" << std::endl;
	return (NULL);
}

AForm	*Intern::newShrubberyCreationForm(const std::string target)
{
	ShrubberyCreationForm *form = new ShrubberyCreationForm(target);
	if (form)
	{
		std::cout << "Intern created new ShrubberyCreationForm" << std::endl;
		return (form);
	}
	else
		std::cout << "ShrubberyCreationForm creation failed" << std::endl;
	return (NULL);
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	AForm* (Intern::*function_ptr[])(std::string) = {&Intern::newPresidentialPardonForm, &Intern::newRobotomyRequestForm, &Intern::newShrubberyCreationForm};
	std::string formType[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	bool	found = false;

	for (int i = 0; i < 3; i++)
	{
		if (formType[i] == name)
		{
			found = true;
			return (this->*function_ptr[i])(target);
		}
	}
	if (!found)
		std::cout << "Form type does not exist, sorry" << std::endl;
	return NULL;
}
