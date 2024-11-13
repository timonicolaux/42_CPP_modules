/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:35:23 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/23 09:33:14 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class	Form;

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

		void	signForm(Form& form);

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
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src);

#endif
