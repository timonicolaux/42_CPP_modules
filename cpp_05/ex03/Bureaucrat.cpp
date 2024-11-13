/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:24:44 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:01:08 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Default constructor called for Bureaucrat " << _name << std::endl;
	try
	{
		if (grade < 1)
		{
			_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Copy constructor called for Bureaucrat " << copy._name << std::endl;
	*this = copy;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for Bureaucrat " << _name << std::endl;
	return ;
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade < 150)
		{
			std::cout << "Grade decremented of 1, grade : " << _grade << std::endl;
			this->_grade++;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade > 1)
		{
			this->_grade--;
			std::cout << "Grade incremented of 1, grade : " << _grade << std::endl;
		}
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade can't be more than 1 ! Grade set to 1.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade can't be less than 150 ! Grade set to 150.";
}

const char*	Bureaucrat::ExecutionGradeTooHighException::what() const throw()
{
	return "Execution grade is too high";
}

const char*	Bureaucrat::ExecutionGradeTooLowException::what() const throw()
{
	return "Execution grade is too low";
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src)
{
	std::cout << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}

void	Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
	return ;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cannot execute " << form.getName() << ". " << e.what() << '\n';
	}
	return ;
}
