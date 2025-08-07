/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:37:00 by mathildelau       #+#    #+#             */
/*   Updated: 2025/08/07 15:36:44 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                               CANONICAL FORM                               */
/* ************************************************************************** */

Point::Point(): _x(0), _y(0)
{
    // std::cout << GREEN << "Default construcor called" << STOP << std::endl;
}

Point::Point(Point const &copy): _x(copy.getX()), _y(copy.getY())
{
    // std::cout << GREEN << "Copy constructor called" << STOP << std::endl;
}

Point &Point::operator=(Point const &rs)
{
    // std::cout << GREEN << "Copy assignment operator called" << STOP << std::endl;
    (void)rs;
    return (*this);
}

Point::~Point()
{
    // std::cout << RED << "Destructor called" << STOP << std::endl;
}


/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Point::Point(const float f1, const float f2) : _x(f1), _y(f2)
{
    // std::cout << GREEN << "Construcor called" << STOP << std::endl;
}

/* ************************************************************************** */
/*                             GETTERS & SETTERS                              */
/* ************************************************************************** */

Fixed Point::getX() const
{
    return(this->_x);
}

Fixed Point::getY() const
{
    return(this->_y);
}