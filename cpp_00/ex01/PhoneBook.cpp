/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:03:10 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/20 12:46:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cout;
using std::endl;
using std::getline;
using std::string;

PhoneBook::PhoneBook()
{
	this->nb_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

std::string	PhoneBook::get_string(string message)
{
	string	input;

	while (42)
	{
		cout << message;
		if (!getline(std::cin, input))
		{
			cout << "\n\nInput error. Program terminated.\n" << endl;
			exit(EXIT_FAILURE);
		}
		else if (input.empty())
		{
			cout << "\nPlease enter a valid input\n" << endl;
		}
		else
			break ;
	}
	return input;
}

void	PhoneBook::add_contact(PhoneBook *book, int *index)
{
	string	str;

	if (*index == 8)
		*index = 0;
	cout << "\n---- Adding a new contact ----\n" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			str = (*book).get_string("Enter your first name : ");
			book->contacts[*index].set_first_name(str);
		}
		else if (i == 1)
		{
			str = (*book).get_string("Enter your last name : ");
			book->contacts[*index].set_last_name(str);
		}
		else if (i == 2)
		{
			str = (*book).get_string("Enter your nickname : ");
			book->contacts[*index].set_nickname(str);
		}
		else if (i == 3)
		{
			str = (*book).get_string("Enter your phone number : ");
			book->contacts[*index].set_phone_number(str);
		}
		else if (i == 4)
		{
			str = (*book).get_string("Enter your darkest secret : ");
			book->contacts[*index].set_darkest_secret(str);
		}
		str = "";
	}
	*index += 1;
	if (PhoneBook::nb_contacts < 8)
		PhoneBook::nb_contacts++;
	cout << "\n---- New contact added ----\n" << endl;
	return ;
}

void	display_header()
{
	cout << " ___________________________________________ " << endl;
	cout << "|     index|first_name| last_name|  nickname|" << endl;
	cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " << endl;
	return ;
}

void	PhoneBook::display_all_contacts(PhoneBook *book)
{
	string	str;
	int	str_len(0);

	if (book->contacts[0].get_first_name().length())
	{
		display_header();
		for (int k = 0; k < PhoneBook::nb_contacts; k++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i == 0)
					cout << "|         " << k << "|";
				else if (i == 1)
					str = book->contacts[k].get_first_name();
				else if (i == 2)
					str = book->contacts[k].get_last_name();
				else if (i == 3)
					str = book->contacts[k].get_nickname();
				str_len = str.length();
				if (str_len < 10 && str_len != 0)
				{
					for (int j = 0; j < (10 - str_len); j++)
						cout << " ";
					cout << str << "|";
				}
				else if (str_len >= 10)
				{
					for (int j = 0; j < 9; j++)
						cout << str[j];
					cout << ".|";
				}
				else if (i != 0 && str_len == 0)
					cout << "          |";
				str = "";
			}
			cout << endl;
		}
		cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " << endl;
	}
	else
		cout << "\nNo contacts to display yet" << endl;
	return ;
}

void	PhoneBook::display_contact(PhoneBook *book)
{
	string	str;
	int	index(-1);

	if (book->contacts[0].get_first_name().length())
	{
		str = (*book).get_string("Please enter an index : ");
		index = atoi(str.c_str());
		if ((index < 0 || index > 7) || (index == 0 && str != "0")\
		|| !book->contacts[index].get_first_name().length())
		{
			cout << "\nIndex does no exist" << endl;
			return ;
		}
		cout << "\nFirst name : ";
		cout << book->contacts[index].get_first_name() << endl;
		cout << "Last name : ";
		cout << book->contacts[index].get_last_name() << endl;
		cout << "Nickname : ";
		cout << book->contacts[index].get_nickname() << endl;
		cout << "Phone number : ";
		cout << book->contacts[index].get_phone_number() << endl;
		cout << "Darkest secret : ";
		cout << book->contacts[index].get_darkest_secret() << endl;
	}
	return ;
}
