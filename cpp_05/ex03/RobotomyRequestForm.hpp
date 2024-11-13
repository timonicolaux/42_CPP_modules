/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:25:17 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:02:25 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);
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
