/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:35:18 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/21 11:37:10 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	formTester(std::string name, int highest, int lowest)
{
	try
	{
		Form(name, highest, lowest);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n' << std::endl;
	}
	return;
}

void	bureaucratTester(std::string name, int grade)
{
	try
	{
		Bureaucrat a(name, grade);
		Form form("Form", 1, 150);
		a.signForm(form);
		form.beSigned(a);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n' << std::endl;
	}
	return;
}

int	main()
{
	formTester("Form 1", 0, 150);
	formTester("Form 2", 1, 151);
	formTester("Form 3", 1, 150);

	bureaucratTester("John", 150);
	bureaucratTester("Bob", 1);

	return 0;
}
