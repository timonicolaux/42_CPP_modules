/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:24:08 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/27 14:49:27 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	my_replace(std::string buffer, const std::string search, const std::string replace)
{
	size_t	position = buffer.find(search);

	while (position != std::string::npos)
	{
		buffer.erase(position, search.length());
		buffer.insert(position, replace);
		position = buffer.find(search, position + replace.length());
	}
	return buffer;
}

int	main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Wrong number of arguments" << std::endl;
	else
	{
		std::string	filename = av[1];
		const std::string	search = av[2];
		const std::string	replace = av[3];
		std::string		buffer;
		std::ifstream	infile;
		std::ofstream	outfile;

		if (!search.length())
		{
			std::cout << "Please enter a value to search" << std::endl;
			return -1;
		}
		if (!replace.length())
		{
			std::cout << "Please enter a value to replace" << std::endl;
			return -1;
		}
		filename += ".replace";
		infile.open(av[1]);
		if (infile.is_open())
		{
			outfile.open(filename.c_str());
			if (outfile.is_open())
			{
				while (std::getline(infile, buffer))
				{
					buffer = my_replace(buffer, search, replace);
					outfile << buffer;
					if (infile.peek() != EOF)
						outfile << std::endl;
				}
			}
			else
			{
				std::cout << "Error while trying to open file" << std::endl;
				infile.close();
				return -1;
			}
		}
		else
		{
			std::cout << "Error while trying to open file" << std::endl;
			return -1;
		}
		infile.close();
		outfile.close();
	}
	return 0;
}
