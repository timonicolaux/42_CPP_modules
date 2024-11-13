/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:02:49 by tnicolau          #+#    #+#             */
/*   Updated: 2024/07/18 11:20:52 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain	&operator=(const Brain& copy);
		void	addIdea(int index, const std::string idea);
};

#endif
