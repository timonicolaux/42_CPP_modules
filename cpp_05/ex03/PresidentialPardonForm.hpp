/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:25:07 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:02:10 by tnicolau         ###   ########.fr       */
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
