/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:36:42 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:26 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const std::string& input)
{
	if (!checkInputValidity(input))
	{
		if (calculator(input) == -1)
			return ;
	}
}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN::~RPN()
{}

RPN	&RPN::operator=(const RPN& src)
{
	if (this != &src)
		this->pile = src.pile;
	return *this;
}

int	RPN::checkInputValidity(const std::string& input)
{
	int	numCounter = 0;
	int	operatorCounter = 0;

	if (!isOperator(input[input.length() - 1]))
	{
		std::cerr << "Error: incomplete expression" << std::endl;
		return -1;
	}
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (input.length() == 1 && !isdigit(input[i]))
		{
			std::cerr << "Error: please enter at least one number" << std::endl;
			return -1;
		}
		if (input[i] == 32)
			i++;
		if (!isdigit(input[i]) && input[i] != 32 && !isOperator(input[i]))
		{
			std::cerr << "Error: forbidden character " << input[i] << " in input" << std::endl;
			return -1;
		}
		if (i + 1 != (int)input.length() && isdigit(input[i]) && isdigit(input[i + 1]))
		{
			std::cerr << "Error: number must be less than 10" << std::endl;
			return -1;
		}
		if (isdigit(input[i]))
			numCounter++;
		if (isOperator(input[i]))
			operatorCounter++;
	}
	if (operatorCounter > numCounter)
	{
		std::cerr << "Error: number of operators is too high" << std::endl;
		return -1;
	}
	if (operatorCounter == numCounter)
	{
		std::cerr << "Error: one operand must be used for two numbers" << std::endl;
		return -1;
	}
	return 0;
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int	RPN::calculator(std::string input)
{
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (isdigit(input[i]))
			pile.push(input[i] - '0');
		else if (input[i] == 32)
			continue;
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			if (makeOperation(input[i]) == -1)
				return -1;
	}
	if (pile.size() > 1)
	{
		std::cerr << "Error: two numbers on pile at end of calculation, check your input" << std::endl;
		return -1;
	}
	std::cout << pile.top() << std::endl;
	return 0;
}

int	RPN::makeOperation(char c)
{
	int	a = pile.top();
	pile.pop();
	int	b = pile.top();
	pile.pop();
	int	result;

	switch (c)
	{
		case '+':
			result = b + a;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = b * a;
			break;
		case '/':
			if (a == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				return -1;
			}
			result = b / a;
			break;
	}
	pile.push(result);
	return 0;
}
