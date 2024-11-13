/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:32:38 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/24 13:00:42 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool	_signed;
		const int	_signGrade;
		const int	_executionGrade;
	public:
		AForm(const std::string name, int signGrade, int executionGrade);
		AForm(const AForm& copy);
		virtual ~AForm();
		AForm &operator=(const AForm& src);
		const std::string&	getName() const;
		bool	checkIfSigned() const;
		int		getSignGrade() const;
		int		getExecutionGrade() const;
		virtual void	beSigned(const Bureaucrat& bureaucrat) = 0;
		void	execute(Bureaucrat const &executor) const;
		virtual void	executeChild(Bureaucrat const & bureaucrat) const = 0;

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

std::ostream	&operator<<(std::ostream &o, const AForm &form);

#endif
