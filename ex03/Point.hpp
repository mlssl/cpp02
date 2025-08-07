/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:29:32 by mathildelau       #+#    #+#             */
/*   Updated: 2025/08/07 14:55:42 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE  "\033[34m"
#define STOP "\033[0m"

class Point
{
    public :
        Point();
        Point(Point const & copy);
        Point & operator=(Point const & rs);
         ~Point();

        Point(const float f1, const float f2);

        Fixed getX() const;
	    Fixed getY() const;
        
    private :
        const Fixed _x;
        const Fixed _y;
};

#endif