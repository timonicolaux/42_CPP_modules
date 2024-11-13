/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:37:36 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/24 11:08:52 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool	_signed;
		const int	_signGrade;
		const int	_executionGrade;
	public:
		Form(const std::string name, int signGrade, int executionGrade);
		Form(const Form& copy);
		~Form();
		Form &operator=(const Form& src);
		const std::string&	getName() const;
		bool	checkIfSigned() const;
		int		getSignGrade() const;
		int		getExecutionGrade() const;
		void	beSigned(const Bureaucrat& bureaucrat);

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
		class AlreadySigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
