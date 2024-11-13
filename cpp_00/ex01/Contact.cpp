/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:03:16 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/19 08:32:43 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_first_name(std::string str)
{
	first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	darkest_secret = str;
}

std::string	Contact::get_first_name()
{
	return first_name;
}

std::string	Contact::get_last_name()
{
	return last_name;
}

std::string	Contact::get_nickname()
{
	return nickname;
}

std::string	Contact::get_phone_number()
{
	return phone_number;
}

std::string	Contact::get_darkest_secret()
{
	return darkest_secret;
}
