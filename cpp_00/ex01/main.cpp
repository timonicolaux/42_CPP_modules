/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:34 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/20 12:46:46 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cout;
using std::endl;
using std::getline;
using std::string;

int	main()
{
	string input;
	string name;
	PhoneBook	book;
	static int	index(0);

	while (42)
	{
		cout << "\n--> List of available commands : ADD - SEARCH - EXIT <--\n" << endl;
		input = book.get_string("Enter your command : ");
		if (!input.compare("EXIT"))
		{
			cout << "\n---- Program terminated -----\n" << endl;
			return 0;
		}
		else if (!input.compare("ADD"))
			book.add_contact(&book, &index);
		else if (!input.compare("SEARCH"))
		{
			book.display_all_contacts(&book);
			book.display_contact(&book);
		}
		else
		{
			if (input.length())
				cout << "\nCommand " << input << " does not exist" << endl;
			else
				cout << "\nCommand does not exist" << endl;
		}
	}
	return 0;
}
