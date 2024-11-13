/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:29:45 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/23 11:29:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat *a = new Bureaucrat("John", 151);

	std::cout << *a;
	a->decrementGrade();
	a->incrementGrade();
	a->incrementGrade();
	delete a;

	std::cout << std::endl;

	Bureaucrat *b = new Bureaucrat("Bob", 1);

	std::cout << *b;
	b->incrementGrade();
	b->decrementGrade();
	b->decrementGrade();
	delete b;

	return 0;
}
