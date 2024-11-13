/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:30:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/23 09:33:25 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
