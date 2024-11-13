/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:24:04 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:22 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Default constructor called for RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	std::cout << "Copy constructor called for RobotomyRequestForm" << std::endl;
	*this = copy;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm " << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	AForm::beSigned(bureaucrat);
	return ;
}

void	RobotomyRequestForm::executeChild(Bureaucrat const & bureaucrat) const
{
	static int robotomyFailed = 0;
	try
	{
		if (!this->checkIfSigned())
			throw RobotomyRequestForm::NotSigned();
		else if (this->getExecutionGrade() > 45)
			throw Bureaucrat::ExecutionGradeTooLowException();
		else if (this->getExecutionGrade() < 45)
			throw Bureaucrat::ExecutionGradeTooHighException();
		else if (robotomyFailed % 2)
		{
			std::cout << "Robotomy failed for " << bureaucrat.getName() << std::endl;
			robotomyFailed++;
		}
		else
		{
			std::cout << "BRRRRrrrzzzzz bRbbbrRRRRR" << std::endl;
			std::cout << _target << " has been robotomized" << std::endl;
			std::cout << "RobotomyRequestForm executed" << std::endl;
			robotomyFailed++;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

const char*	RobotomyRequestForm::NotSigned::what() const throw()
{
	return "RobotomyRequestForm not signed !";
}

