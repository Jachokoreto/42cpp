/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:41 by jatan             #+#    #+#             */
/*   Updated: 2022/07/13 21:11:07 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	int bNum = 4;
	float cNum = 2.0f;
	Fixed a;
	Fixed const b(Fixed(bNum) * Fixed(cNum));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	a = Fixed(bNum) + Fixed(cNum);
	std::cout << "Testing + : " << a << std::endl;
	a = Fixed(bNum) - Fixed(cNum);
	std::cout << "Testing - : " << a << std::endl;
	a = Fixed(bNum) * Fixed(cNum);
	std::cout << "Testing * : " << a << std::endl;
	a = Fixed(bNum) / Fixed(cNum);
	std::cout << "Testing / : " << a << std::endl;
	return 0;
}