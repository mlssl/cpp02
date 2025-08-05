/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:21:38 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/05 15:26:58 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bit = 8;

											/*CANONIC PART*/

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

//operator =
Fixed &Fixed::operator=(Fixed const & rs)
{
	std::cout << GREEN << "Copy assignment operator called" << STOP << std::endl;
	this->_n = rs.getRawBits();

	return (*this);
}


										/*CONSTRUCTORS*/

//int
Fixed::Fixed(const int intValue)
{
	std::cout << GREEN << "Int constructor called" << STOP << std::endl;
	this->_n = intValue << this->_bit;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << GREEN << "Float constructor called" << STOP << std::endl;
}


											/*OPERATOR*/
//operator <<
std::ostream & operator<<(std::ostream & o, Fixed const & rs)
{
	o << rs.toFloat();
	return (o);
}


										/*GETTER AND SETTER*/
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


									/*MEMBER FUNCTION*/
