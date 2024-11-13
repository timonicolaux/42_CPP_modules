/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:49:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Default constructor called for ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	std::cout << "Copy constructor called for ShrubberyCreationForm" << std::endl;
	*this = copy;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called for ShrubberyCreationForm " << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
	return ;
}

void	ShrubberyCreationForm::executeChild(Bureaucrat const & bureaucrat) const
{
	try
	{
		if (!this->checkIfSigned())
			throw ShrubberyCreationForm::NotSigned();
		else if (this->getExecutionGrade() > 137)
			throw Bureaucrat::ExecutionGradeTooLowException();
		else if (this->getExecutionGrade() < 137)
			throw Bureaucrat::ExecutionGradeTooHighException();
		else
		{
			std::cout << "ShrubberyCreationForm executed for " << bureaucrat.getName() << std::endl;
			std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
			outfile <<
				"       # #### ####" << std::endl <<
				"     ### \\/#|### |/####" << std::endl <<
				"    ##\\/#/ \\||/##/_/##/_##" << std::endl <<
				"  ###  \\/###|/ \\/ # ###" << std::endl <<
				" ##_\\_#\\_\\## | #/###_/_#### " << std::endl <<
				"## #### # \\ #| /  #### ##/##" << std::endl <<
				"  __#_--###`  |{,###---###-~" << std::endl <<
				"            \\ }{" << std::endl <<
				"             }}{" << std::endl <<
				"             }}{" << std::endl <<
				"             {{}" << std::endl <<
				"             {{}" << std::endl <<
				"           __/__\\__" << std::endl <<
				std::endl;
			outfile.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

const char*	ShrubberyCreationForm::NotSigned::what() const throw()
{
	return "ShrubberyCreationForm not signed !";
}

