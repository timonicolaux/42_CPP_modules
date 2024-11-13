/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:46 by tnicolau          #+#    #+#             */
/*   Updated: 2024/10/02 14:19:31 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <limits.h>

class	PmergeMe
{
	private:
		std::vector<unsigned int>	first_vector;
		std::vector<unsigned int>	smallest_vector;
		std::vector<unsigned int>	biggest_vector;

		std::deque<unsigned int>	first_deque;
		std::deque<unsigned int>	smallest_deque;
		std::deque<unsigned int>	biggest_deque;
		bool			unpaired;
		unsigned int	unpaired_value;
		PmergeMe();
	public:
		PmergeMe(const std::string& input);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe& src);
		void	addToVector(const std::string& input);
		void	addToDeque(const std::string& input);
		void	sortVector();
		void	sortDeque();
		void	sortBiggestRecursiveVector(std::vector<unsigned int>& src);
		void	sortBiggestRecursiveDeque(std::deque<unsigned int>& src);
		void	binaryInsertionVector(unsigned int n);
		void	binaryInsertionDeque(unsigned int n);
		void	makeFinalVector();
		void	makeFinalDeque();
		std::vector<unsigned int>	generateJacobsthalSequence(unsigned int n);
		class NotEnoughNumbers : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NumberTooBig : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
