/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:41 by jatan             #+#    #+#             */
/*   Updated: 2022/09/04 05:06:36 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/**
 * What is fixed point?
 * - In computing, fixed-point refers to a method of representing fractional
 * (non-integer) numbers by storing a fixed number of digits of their fractional part.
 * - So, we can set our desired amount of bits to decide its precision
 *
 * Fixed point
 * - used to represent a limited range of values
 *
 * vs Floating point
 * - used to represent a wide range of values
 *
 */

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}