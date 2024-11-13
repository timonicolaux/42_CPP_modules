/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:24:55 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:07:54 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	std::cout << std::endl;

	AForm* rrf2;
	rrf2 = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	delete rrf2;

	std::cout << std::endl;

	AForm* rrf3;
	rrf3 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	delete rrf3;

	std::cout << std::endl;

	AForm* rrf4;
	rrf4 = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	delete rrf4;
	std::cout << std::endl;
	return 0;
}
