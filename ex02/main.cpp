/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:01 by mlaussel          #+#    #+#             */
/*   Updated: 2025/08/07 14:24:09 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{ 
	std::cout << BLUE<< "		MAIN SUBJECT		" << STOP << std::endl;
	
	Fixed m;
	Fixed const n( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << m << std::endl;
	std::cout << ++m << std::endl;
	std::cout << m << std::endl;
	std::cout << m++ << std::endl;
	std::cout << m << std::endl;
	std::cout << n << std::endl;
	std::cout << Fixed::max( m, n ) << std::endl << std::endl << std::endl;

	std::cout << BLUE << "		PERSONAL MAIN		" << STOP << std::endl;

	std::cout << YELLOW << "----- Constructeurs et opérateurs arithmétiques -----" << STOP << std::endl;
	Fixed a(10);                   // 10.0
	Fixed b(2.5f);                 // 2.5
	Fixed c = a + b;              // 10.0 + 2.5 = 12.5
	Fixed d = a - b;              // 10.0 - 2.5 = 7.5
	Fixed e = a * b;              // 10.0 * 2.5 = 25.0
	Fixed f = a / b;              // 10.0 / 2.5 = 4.0

	std::cout << "a: " << a << " must be 10"  << std::endl;             // 10
	std::cout << "b: " << b << " must be 2.5" << std::endl;             // 2.5
	std::cout << "a + b: " << c << " must be 12.5" << std::endl;         // 12.5
	std::cout << "a - b: " << d << " must be 7.5" << std::endl;         // 7.5
	std::cout << "a * b: " << e << " must be 25" << std::endl;         // 25
	std::cout << "a / b: " << f << " must be 4" << std::endl;         // 4

	std::cout << YELLOW <<  "----- Opérateurs de comparaison -----" << STOP << std::endl;;
	std::cout << "a > b: " << (a > b) << " must be 1" << std::endl;    // 1
	std::cout << "a < b: " << (a < b) << " must be 0" << std::endl;    // 0
	std::cout << "a >= b: " << (a >= b) << " must be 1" << std::endl;  // 1
	std::cout << "a <= b: " << (a <= b) << " must be 0" << std::endl;  // 0
	std::cout << "a == b: " << (a == b) << " must be 0" << std::endl;  // 0
	std::cout << "a != b: " << (a != b) << " must be 1" << std::endl;  // 1

	std::cout << YELLOW << "----- Incrémentation / Décrémentation -----" << STOP << std::endl;;
	Fixed g;
	std::cout << "g: " << g << " must be 0" << std::endl;              // 0
	std::cout << "++g: " << ++g << " must be 0.00390625" << std::endl;          // 0.00390625 (1/256)
	std::cout << "g: " << g << " must be 0.00390625" << std::endl;              // 0.00390625
	std::cout << "g++: " << g++ << " must be 0.00390625" << std::endl;          // 0.00390625 (avant incrémentation)
	std::cout << "g: " << g << " must be 0.0078125" << std::endl;              // 0.0078125

	std::cout << "--g: " << --g << " must be 0.00390625" << std::endl;          // 0.00390625
	std::cout << "g--: " << g-- << " must be 0.00390625" << std::endl;          // 0.00390625
	std::cout << "g: " << g << " must be 0" << std::endl;              // 0

	std::cout << YELLOW << "----- Fonctions statiques min / max -----" << STOP << std::endl;;
	Fixed h(42.42f);
	Fixed i(10);

	std::cout << "min(h, i): " << Fixed::min(h, i) << " must be 10" << std::endl;  // 10
	std::cout << "max(h, i): " << Fixed::max(h, i) << " must be 42.4219" << std::endl;  // 42.4219

	const Fixed j(5.5f);
	const Fixed k(7.75f);

	std::cout << "min(j, k): " << Fixed::min(j, k) << " must be 5.5" << std::endl;  // 5.5
	std::cout << "max(j, k): " << Fixed::max(j, k) << " must be 7.75" << std::endl;  // 7.75

	return 0; 
}
