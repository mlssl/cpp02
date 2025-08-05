/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:32:32 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/05 13:49:56 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE  "\033[34m"
#define STOP "\033[0m"

class Fixed
{
	public :
		Fixed(); //constructor
		Fixed(Fixed const & f); //copy
		~Fixed(); //destructor

		Fixed & operator=(Fixed const & rs); //operator

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


	private :
		int _n;
		static const int _bit;
};

#endif
