/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:31:37 by tnicolau          #+#    #+#             */
/*   Updated: 2024/09/25 13:16:33 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Span
{
	private:
		unsigned int	_N;
		std::vector<int>	_array;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();
		Span	&operator=(const Span& src);
		void	addNumber(int number);
		void	addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		class	ArrayIsFull : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	ArrayIsTooSmall : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	NotEnoughSpace : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
