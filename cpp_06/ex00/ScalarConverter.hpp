/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timonicolaux <timonicolaux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:14:00 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/19 18:19:40 by timonicolau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
	public:
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &src);
		static void convert(std::string input);
};

#endif
