/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:21:17 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/22 10:05:11 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	pointValue = false;
bool	hasDecimalZeros = false;

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called for ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	std::cout << "Copy constructor called for ScalarConverter" << std::endl;
	*this = copy;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Default destructor called for ScalarConverter" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this == &src)
		return *this;
	return *this;
}

const char	*toChar(std::string& input)
{
	const char	*toChar = input.c_str();
	return toChar;
}

int	toInt(std::string& input)
{
	int	toInt;
	toInt = atoi(input.c_str());
	return toInt;
}

bool	toAscii(std::string& input)
{
	int num = toInt(input);
	if (num > 32 && num < 127)
	{
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		return true;
	}
	return false;
}

double	toDouble(std::string& input)
{
	double	to_double;
	char	*endptr;

	if (input[input.length() - 1] == 'f')
		input.erase(input.length() - 1);
	to_double = strtod(input.c_str(), &endptr);
	if (input[0] == '-' && (to_double * 1 == 0))
	{
		input.erase(0);
		to_double = strtod(input.c_str(), &endptr);
	}
	if (*endptr != '\0')
	{
		std::cout << "Double conversion error, terminating program" << std::endl;
		exit(EXIT_FAILURE);
	}
	return to_double;
}

float	toFloat(std::string& input)
{
	double	to_double = toDouble(input);
	return static_cast<float>(to_double);
}

bool	isNumber(std::string& input)
{
	int		numberOfNums = 0;

	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (numberOfNums == 6)
		{
			std::cout << "Number is too big, try a smaller number" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			return false;
		else if (!std::isdigit(input[i]))
		{
			if (input[i] == '.' && !pointValue)
			{
				//case 42.
				if (i + 1 == input.length())
					return false;
				pointValue = true;
				numberOfNums = 0;
				if (input[i + 1] == '0')
				{
					int	j = i + 1;
					int count = 0;
					while (input[j] == '0')
					{
						count++;
						j++;
					}
					//case 42.00 (will be rounded to 42)
					if (!input[j] || (input[j] == 'f' && !input[j + 1]))
						hasDecimalZeros = true;
					//case 42.00003 (will be rounded to 42)
					else if (count == 4)
						hasDecimalZeros = true;
				}
			}
			//case 42.0.
			else if (input[i] == '.' && pointValue)
				return false;
			//case 42.f
			else if (i != 0 && input[i] == 'f' && input[i - 1] == '.')
				return false;
			//case 42.0f0
			else if (i + 1 != input.length() && input[i] == 'f')
				return false;
			else if (input[i] == 'f' && i + 1 == input.length())
				return true;
			else
				return false;
		}
		else if (std::isdigit(input[i]))
			numberOfNums++;
	}
	return true;
}

void	ScalarConverter::convert(std::string input)
{
	std::string	input_cpy = input;

	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan";
	}
	else if (input == "-inff" || input == "-inf" || input == "+inff" || input == "+inf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		if (input == "-inff" || input == "+inff")
		{
			std::cout << "int: " << input.erase(input.length() - 1) << std::endl;
			std::cout << "float: " << input_cpy << std::endl;
			std::cout << "double: " << input_cpy.erase(input_cpy.length() - 1);
		}
		else if (input == "-inf" || input == "+inf")
		{
			std::cout << "int: " << input << std::endl;
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input;
		}
	}
	else if (!isNumber(input))
	{
		std::cout << "char: " << toChar(input) << std::endl;
		std::cout << "int: " << "Non displayable" << std::endl;
		std::cout << "float: " << "Non displayable" << std::endl;
		std::cout << "double: " << "Non displayable";
	}
	else if ((isNumber(input) && !pointValue) || hasDecimalZeros)
	{
		if (!toAscii(input))
			std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << toInt(input) << std::endl;
		std::cout << "float: " << toFloat(input) << ".0f" << std::endl;
		std::cout << "double: " << toDouble(input) << ".0";
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << toInt(input) << std::endl;
		std::cout << "float: " << toFloat(input) << "f" << std::endl;
		std::cout << "double: " << toDouble(input);
	}
	pointValue = false;
	hasDecimalZeros = false;
	return ;
}
