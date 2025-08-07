/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:01 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/07 16:39:26 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	area(Point a, Point b, Point c)
{
	Fixed area;
	
	area = (Fixed(0.5f) * ((a.getX() * (b.getY() - c.getY())) 
						+ (b.getX() * (c.getY() - a.getY()))
						+ (c.getX() * (a.getY() - b.getY()))));
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
 {
	Fixed areaABC = area(a, b, c);
	Fixed areaPBC = area(point, b, c);
	Fixed areaAPC = area(a, point, c);
	Fixed areaABP = area(a, b, point);
	
	Fixed total = areaPBC + areaAPC + areaABP;
	
	if (total == areaABC && areaPBC > 0 && areaAPC > 0 && areaABP > 0)
		return (true);
	return (false);
 }

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(1, 1);
	Point outside(20, 20);
	Point edge(0, 5);
	Point vertex(0, 0);
	Point onPoint(10, 0);

	std::cout << "Inside (1,1): " << bsp(a, b, c, inside) << " (should be 1)" << std::endl;
	std::cout << "Outside (20,20): " << bsp(a, b, c, outside) << " (should be 0)" << std::endl;
	std::cout << "On edge (0,5): " << bsp(a, b, c, edge) << " (should be 0)" << std::endl;
	std::cout << "On vertex (0,0): " << bsp(a, b, c, vertex) << " (should be 0)" << std::endl;
	std::cout << "On point: " << bsp(a, b, c, onPoint) << " (should be 0)" << std::endl;

	return 0;
}

