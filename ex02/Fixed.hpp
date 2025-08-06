/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:32:32 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/06 14:40:02 by mathildelau      ###   ########.fr       */
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
		//canonical
		Fixed(); //constructor
		Fixed(Fixed const & f); //copy
		~Fixed(); //destructor
		Fixed & operator=(Fixed const & rs); //operator

		Fixed(const int intValue);
		Fixed(const float floatValue);

		/*getter and setter*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*members functions*/
		float	toFloat(void) const;
		int		toInt( void ) const;

		static Fixed&	min(Fixed& nb1, Fixed& nb2);
		static Fixed&	max(Fixed& nb1, Fixed& nb2);
	
		static const Fixed& min(const Fixed& nb1, const Fixed& nb2);
		static const Fixed& max(const Fixed& nb1, const Fixed& nb2);

		/*operator*/
		int operator>(Fixed const & rs);
		int operator<(Fixed const & rs);
		int operator>=(Fixed const & rs);
		int operator<=(Fixed const & rs);
		int operator==(Fixed const & rs);
		int operator!=(Fixed const & rs);

		/*arithmetic*/
		Fixed operator+(Fixed const & rs);
		Fixed operator-(Fixed const & rs);
		Fixed operator*(Fixed const & rs);
		Fixed operator/(Fixed const & rs);

		/*increment and decrement*/
		Fixed & operator++();
		Fixed & operator--();
		Fixed operator++(int);
		Fixed operator--(int);

	private :
		int _n;
		static const int _bit;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rs);

#endif
