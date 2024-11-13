/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:00 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/13 10:17:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int signGrade, int executionGrade) : _name(name), _signed(false), _signGrade(signGrade), _executionGrade(executionGrade)
{
	std::cout << "Default constructor called for " << _name << std::endl;
	if (_signGrade < 1)
	{
		std::cout << "Wrong sign grade. ";
		throw Form::GradeTooHighException();
	}
	else if (_executionGrade < 1)
	{
		std::cout << "Wrong execution grade. ";
		throw Form::GradeTooHighException();
	}
	else if (_signGrade > 150)
	{
		std::cout << "Wrong sign grade. ";
		throw Form::GradeTooLowException();
	}
	else if (_executionGrade > 150)
	{
		std::cout << "Wrong execution grade. ";
		throw Form::GradeTooLowException();
	}
	return ;
}

Form::Form(const Form& copy) : _name(copy.getName() + "_copy"), _signed(false), _signGrade(1), _executionGrade(2)
{
	std::cout << "Copy constructor called for " << _name << std::endl;
	*this = copy;
	return ;
}

Form::~Form()
{
	std::cout << "Destructor called for " << _name << std::endl;
	return ;
}

Form	&Form::operator=(const Form& src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	std::cout << "Form : " << form.getName() << std::endl;
	std::cout << "Form status : " << form.checkIfSigned() << std::endl;
	std::cout << "Sign grade : " << form.getSignGrade() << std::endl;
	std::cout << "Execution grade : " << form.getExecutionGrade() << std::endl;
	std::cout << std::endl;
	return o;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	try
	{
		if (_signed)
			throw Form::AlreadySigned();
		else if (bureaucrat.getGrade() <= _signGrade)
		{
			_signed = true;
			std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
		}
		else
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::checkIfSigned() const
{
	return _signed;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecutionGrade() const
{
	return _executionGrade;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade to high to sign !";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign !";
}

const char*	Form::AlreadySigned::what() const throw()
{
	return "Form already signed !";
}

const char*	Form::NotSigned::what() const throw()
{
	return "Form not signed !";
}
