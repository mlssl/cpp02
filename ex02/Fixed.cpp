/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:21:38 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/07 14:03:39 by mathildelau      ###   ########.fr       */
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
	//std::cout << GREEN << "Default constructor called" << STOP << std::endl;
}

/**
 * @brief Destructor.
 * Called when at the end.
 */
Fixed::~Fixed()
{
	//std::cout << RED << "Destructor called" << STOP << std::endl;
}

/**
 * @brief Copy constructor.
 * Creates a new Fixed object as a copy of another.
 * @param f The Fixed object to copy.
 */
Fixed::Fixed(Fixed const &f)
{
	// std::cout << GREEN << "Copy constructor called" << STOP << std::endl;
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
	// std::cout << GREEN << "Copy assignment operator called" << STOP << std::endl;
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
	// std::cout << GREEN << "Int constructor called" << STOP << std::endl;
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
	// std::cout << GREEN << "Float constructor called" << STOP << std::endl;
	this->_n = roundf(floatValue * (1 << this->_bit));
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

int	Fixed::operator>(Fixed const & rs)
{
	return (this->_n > rs.getRawBits());
}

int	Fixed::operator<(Fixed const & rs)
{
	return (this->_n < rs.getRawBits());
}

int	Fixed::operator>=(Fixed const & rs)
{
	return (this->_n >= rs.getRawBits());
}

int	Fixed::operator<=(Fixed const & rs)
{
	return (this->_n <= rs.getRawBits());
}

int	Fixed::operator==(Fixed const & rs)
{
	return (this->_n == rs.getRawBits());
}

int	Fixed::operator!=(Fixed const & rs)
{
	return (this->_n != rs.getRawBits());
}

/* ************************************************************************** */
/*                                 ARITHMETIC                                 */
/* ************************************************************************** */

/**
 * @brief `add`
 *
 * use setRawBits because can't directly do result = _n + rs because there are int. 
 * @param rs The Fixed object to add.
 * @return A new Fixed object representing the sum.
 */
Fixed Fixed::operator+(Fixed const & rs)
{
	Fixed result;
	result.setRawBits(this->_n + rs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const & rs)
{
	Fixed result;
	result.setRawBits(this->_n - rs.getRawBits());
	return (result);
}

/**
 * @brief 
 * 
 * >> : Convert a fixed point to an int. Divide by 256 (2⁸)
 * 
 * If we multiply, the numbers will be too large so we divide by bit.
 */
Fixed Fixed::operator*(Fixed const & rs)
{
	Fixed result;
	result.setRawBits((this->_n * rs.getRawBits()) >> _bit);
	return (result);
}

/**
 * @brief 
 * 
 * << : Converts an int to a fixed-point. Multiplies by 256 (2⁸)
 * 
 * If we only do one division, we lose precision so we multiply by bit.
 */
Fixed Fixed::operator/(Fixed const & rs)
{
    Fixed result;
    result.setRawBits((this->_n / rs.getRawBits()) << _bit);
    return (result);
}

/* ************************************************************************** */
/*                                 INCREMENT AND DECREMENT                    */
/* ************************************************************************** */

/**
 * @brief Pre-increment operator (++x).
 * Increments the fixed-point value by 1 and returns a reference to the updated object.
 * More efficient than post-increment because it does not create a temporary copy.
 * @return Reference to the incremented Fixed object.
 */
Fixed &Fixed::operator++()
{
	this->_n++;
	return (*this);
}

/**
 * @brief Pre-decrement operator (--x).
 * Decrements the fixed-point value by 1 and returns a reference to the updated object.
 * More efficient than post-decrement because it does not create a temporary copy.
 * @return Reference to the decremented Fixed object.
 */
Fixed &Fixed::operator--()
{
	this->_n--;
	return (*this);
}

/**
 * @brief Post-increment operator (x++).
 * Creates a copy of the current object, increments the original, and returns the copy.
 * This preserves the value before incrementing, as expected in post-increment operations.
 * 
 * The purpose of the post-increment is to:
 * 
 * - Return the old value (the one before the increment).
 * 
 * - But still modify the object so that, after the operation, it is properly incremented
 * @param Unused int parameter differentiates this from the pre-increment version.
 * @return Fixed object representing the value before incrementing.
 */
Fixed Fixed::operator++(int)
{
	Fixed result;
	
	result = *this;
	this->_n++;
	return (result);
}

/**
 * @brief Post-decrement operator (x--).
 * Creates a copy of the current object, decrements the original, and returns the copy.
 * This preserves the value before decrementing, as expected in post-decrement operations.
 * 
 *  * The purpose of the post-increment is to:
 * 
 * - Return the old value (the one before the increment).
 * 
 * - But still modify the object so that, after the operation, it is properly incremented
 * @param Unused int parameter differentiates this from the pre-decrement version.
 * @return Fixed object representing the value before decrementing.
 */
Fixed Fixed::operator--(int)
{
	Fixed result;
	
	result = *this;
	this->_n--;
	return (result);
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

Fixed &Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1.toFloat() < nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

Fixed &Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1.toFloat() > nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}


const Fixed &Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.toFloat() < nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}

const Fixed &Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1.toFloat() > nb2.toFloat())
		return (nb1);
	else
		return (nb2);
}