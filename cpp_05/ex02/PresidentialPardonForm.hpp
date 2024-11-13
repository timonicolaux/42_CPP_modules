/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:54:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:14 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
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
