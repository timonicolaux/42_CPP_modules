/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:24:50 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:01:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat& src);
		const std::string&	getName() const;
		int		getGrade() const;
		void	decrementGrade();
		void	incrementGrade();
		void	signForm(AForm& form);
		void	executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ExecutionGradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ExecutionGradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src);

#endif
