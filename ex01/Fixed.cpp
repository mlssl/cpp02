/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:21:38 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/06 11:47:17 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

/**
 * @brief Integer constructor.
 *
 * Converts an integer to fixed-point representation.
 * In fixed-point format, the number is stored as an integer scaled by `2^_bit`.
 * Shifting left by `_bit` bits (`intValue << _bit`) is equivalent to 
 * multiplying by `2^_bit`, which reserves `_bit` bits for the fractional part.
 *
 * @param intValue Integer value to convert.
 */
Fixed::Fixed(const int intValue)
{
	std::cout << GREEN << "Int constructor called" << STOP << std::endl;
	this->_n = intValue << this->_bit;
}

/**
 * @brief Floating-point constructor.
 *
 * Converts a floating-point value to fixed-point representation.
 * Multiplying the float by `2^_bit` (done using `(1 << _bit)`) scales it
 * so the fractional part can be stored as an integer. The result is then 
 * rounded using `roundf` to minimize conversion errors.
 *
 * @param floatValue Floating-point value to convert.
 */
Fixed::Fixed(const float floatValue)
{
	std::cout << GREEN << "Float constructor called" << STOP << std::endl;
	this->_n = roundf(floatValue * (1 << this->_bit));
}


/* ************************************************************************** */
/*                                 OPERATORS                                  */
/* ************************************************************************** */

/**
 * @brief Overloads the insertion (<<) operator.
 * Outputs the floating-point representation of the Fixed object.
 * @param o Output stream.
 * @param rs Fixed object to output.
 * @return The output stream.
 */
std::ostream & operator<<(std::ostream & o, Fixed const & rs)
{
	o << rs.toFloat();
	return (o);
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

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

/**
 * @brief Converts the fixed-point value to a floating-point number.
 *
 * The raw value `_n` stores the number as an integer scaled by `2^_bit`.
 * To recover the real floating-point value, we divide by `2^_bit` 
 * (which is done using `(1 << _bit)`, equivalent to `2^_bit`).
 *
 * @return Floating-point representation of the fixed-point value.
 */
float	Fixed::toFloat() const
{
	return ((float)this->_n / (1 << this->_bit));
}

/**
 * @brief Converts the fixed-point value to an integer.
 *
 * Since `_n` is scaled by `2^_bit`, shifting it right by `_bit` bits 
 * (`_n >> _bit`) effectively divides by `2^_bit`, discarding the fractional part.
 *
 * @return Integer representation of the fixed-point value.
 */
int		Fixed::toInt(void) const
{
	return (this->_n >> this->_bit);
}