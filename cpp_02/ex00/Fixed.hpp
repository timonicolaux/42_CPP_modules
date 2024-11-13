/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:50:38 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/26 14:06:48 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int	_int;
		static const int _bits;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
