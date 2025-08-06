/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:21:38 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/06 11:44:58 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

/* ************************************************************************** */
/*                               CANONICAL FORM                               */
/* ************************************************************************** */

/**
 * @brief Default constructor. 
 * Initializes the fixed-point number to 0.
 */
Fixed::Fixed() : _n(0)
{
	std::cout << GREEN << "Default constructor called" << STOP << std::endl;
}

/**
 * @brief Destructor.
 * Called when at the end.
 */
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << STOP << std::endl;
}

/**
 * @brief Copy constructor.
 * Creates a new Fixed object as a copy of another.
 * @param f The Fixed object to copy.
 */
Fixed::Fixed(Fixed const &f)
{
	std::cout << GREEN << "Copy constructor called" << STOP << std::endl;
	*this = f;
}

/**
 * @brief Copy assignment operator.
 * Assigns the value of another Fixed object to this one.
 * @param rs The Fixed object to copy.
 * @return A reference to this Fixed object.
 */
Fixed &Fixed::operator=(Fixed const & rs)
{
	std::cout << GREEN << "Copy assignment operator called" << STOP << std::endl;
	this->_n = rs.getRawBits();

	return (*this);
}

/* ************************************************************************** */
/*                             GETTERS & SETTERS                              */
/* ************************************************************************** */

/**
 * @brief Returns the raw fixed-point value.
 * @return The raw integer value representing the fixed-point number.
 */
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

/**
 * @brief Sets the raw fixed-point value.
 * @param raw The raw integer value to set.
 */
void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}
