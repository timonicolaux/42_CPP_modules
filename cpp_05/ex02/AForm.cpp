/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:32:47 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:57:44 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int signGrade, int executionGrade) : _name(name), _signed(false), _signGrade(signGrade), _executionGrade(executionGrade)
{
	std::cout << "Default constructor called for AForm" << std::endl;
	return ;
}

AForm::AForm(const AForm& copy) : _name(copy.getName() + "_copy"), _signed(false), _signGrade(1), _executionGrade(2)
{
	std::cout << "Copy constructor called for AForm" << std::endl;
	*this = copy;
	return ;
}

AForm::~AForm()
{
	std::cout << "Destructor called for AForm" << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm& src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	std::cout << "AForm : " << form.getName() << std::endl;
	std::cout << "AForm status : " << form.checkIfSigned() << std::endl;
	std::cout << "Sign grade : " << form.getSignGrade() << std::endl;
	std::cout << "Execution grade : " << form.getExecutionGrade() << std::endl;
	std::cout << std::endl;
	return o;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	try
	{
		if (_signed)
			throw AForm::AlreadySigned();
		else if (bureaucrat.getGrade() <= _signGrade)
		{
			_signed = true;
			std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw AForm::NotSigned();
	else
	{
		std::cout << executor.getName() << " executes form : " << this->_name << std::endl;
		executeChild(executor);
	}
	return ;
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool	AForm::checkIfSigned() const
{
	return _signed;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecutionGrade() const
{
	return _executionGrade;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade to high to sign !";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign !";
}

const char*	AForm::AlreadySigned::what() const throw()
{
	return "Form already signed !";
}

const char*	AForm::NotSigned::what() const throw()
{
	return "Form not signed !";
}
