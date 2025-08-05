/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:21:38 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/05 14:04:35 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

//constructor
Fixed::Fixed() : _n(0)
{
	std::cout << GREEN << "Default constructor called" << STOP << std::endl;
}

//destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << STOP << std::endl;
}

//copy
Fixed::Fixed(Fixed const &f)
{
	std::cout << GREEN << "Copy constructor called" << STOP << std::endl;
	*this = f;
}

//operator
Fixed &Fixed::operator=(Fixed const & rs)
{
	std::cout << GREEN << "Copy assignment operator called" << STOP << std::endl;
	this->_n = rs.getRawBits();

	return (*this);
}

//getters
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

//setters
void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}
