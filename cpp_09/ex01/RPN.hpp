/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:35:36 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 10:34:31 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class	RPN
{
	private:
		std::stack<int>	pile;
		RPN();
	public:
		RPN(const std::string& input);
		RPN(const RPN& copy);
		~RPN();
		RPN	&operator=(const RPN& src);
		int	checkInputValidity(const std::string& input);
		int	calculator(std::string input);
		int	makeOperation(char c);
		bool	isOperator(char c);
};

#endif
