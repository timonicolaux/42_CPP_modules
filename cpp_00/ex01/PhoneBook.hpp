/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:41 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/20 12:46:25 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(PhoneBook *book, int *index);
		void	display_all_contacts(PhoneBook *book);
		void	display_contact(PhoneBook *book);
		std::string	get_string(std::string message);
	private:
		Contact	contacts[8];
		int	nb_contacts;
};

#endif
