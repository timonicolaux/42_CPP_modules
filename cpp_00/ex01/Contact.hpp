/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:03:43 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/19 11:10:44 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

using std::string;

class	Contact
{
	public:
		void	set_first_name(string name);
		void	set_last_name(string str);
		void	set_nickname(string str);
		void	set_phone_number(string str);
		void	set_darkest_secret(string str);
		string	get_first_name();
		string	get_last_name();
		string	get_nickname();
		string	get_phone_number();
		string	get_darkest_secret();
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
};

#endif
