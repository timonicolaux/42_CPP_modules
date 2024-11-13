/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:55:17 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:18 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Default constructor called for PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	std::cout << "Copy constructor called for PresidentialPardonForm" << std::endl;
	*this = copy;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called for PresidentialPardonForm " << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
	return ;
}

void	PresidentialPardonForm::executeChild(Bureaucrat const & bureaucrat) const
{
	try
	{
		if (!this->checkIfSigned())
			throw PresidentialPardonForm::NotSigned();
		else if (this->getExecutionGrade() > 5)
			throw Bureaucrat::ExecutionGradeTooLowException();
		else if (this->getExecutionGrade() < 5)
			throw Bureaucrat::ExecutionGradeTooHighException();
		else
		{
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
			std::cout << "PresidentialPardonForm executed for " << bureaucrat.getName() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

const char*	PresidentialPardonForm::NotSigned::what() const throw()
{
	return "PresidentialPardonForm not signed !";
}
