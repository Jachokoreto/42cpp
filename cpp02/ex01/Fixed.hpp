/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:56:36 by jatan             #+#    #+#             */
/*   Updated: 2022/09/04 04:58:29 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{

public:
	Fixed(void);
	Fixed(const int value);	  // * integer constructor
	Fixed(const float value); // * floating point constructor
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	float toFloat(void) const; // * Int to Fixed point
	int toInt(void) const;	   // * Fixed point to Int

	int getRawBits(void) const;
	void setRawbits(int const raw);

private:
	int _value;
	static const int _fracBits;
};

ostream &operator<<(ostream &o, Fixed const &rhs); // * << operator overload

#endif /* ********************************************************** Fixed_H */