/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:47:28 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:35 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
		void	executeChild(Bureaucrat const & bureaucrat) const;
		std::string	getTarget() const;
		void	beSigned(const Bureaucrat& bureaucrat);
		class NotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
