/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:32:32 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 10:57:51 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubberyTester()
{
	ShrubberyCreationForm shrubberyForm("ShrubberyForm");
	Bureaucrat a("Bobby", 146);

	a.executeForm(shrubberyForm);
	shrubberyForm.beSigned(a);
	a.incrementGrade();
	shrubberyForm.beSigned(a);
	a.executeForm(shrubberyForm);
	return;
}

void	robotomyTester()
{
	RobotomyRequestForm RobotomyForm("RobotomyForm");
	Bureaucrat b("John", 73);

	b.executeForm(RobotomyForm);
	RobotomyForm.beSigned(b);
	b.incrementGrade();
	RobotomyForm.beSigned(b);
	b.executeForm(RobotomyForm);
	return;
}

void	presidentialTester()
{
	PresidentialPardonForm presidentialForm("PresidentialForm");
	Bureaucrat c("Alfred", 26);

	c.executeForm(presidentialForm);
	presidentialForm.beSigned(c);
	c.incrementGrade();
	presidentialForm.beSigned(c);
	c.executeForm(presidentialForm);
	return;
}

int	main()
{
	shrubberyTester();
	std::cout << "\n\n";
	robotomyTester();
	std::cout << "\n\n";
	presidentialTester();
	std::cout << "\n\n";
	return 0;
}
