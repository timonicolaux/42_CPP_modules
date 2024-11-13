/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:53:56 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 11:42:06 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	array;
		BitcoinExchange();
	public:
		BitcoinExchange(const std::string& file);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange& src);
		void	createDatabase();
		void	openFile(const std::string& src);
		int	checkDateValidity(const std::string& date);
		int	checkYear(const std::string& buffer);
		int	checkMonth(const std::string& buffer);
		int	checkDay(const std::string& src_str, const std::string& month_str);
		int	checkSeparator(const std::string& src);
		int	checkNumberValidity(std::string src);
		int	compareDates(std::string date);
		std::string	decreaseDate(std::string date);
		class FileCouldNotOpen : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
