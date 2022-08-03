/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:56:36 by jatan             #+#    #+#             */
/*   Updated: 2022/07/13 23:05:56 by jatan            ###   ########.fr       */
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
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawbits(int const raw);

	bool operator>(const Fixed &fixed);
	bool operator>=(const Fixed &fixed);
	bool operator<(const Fixed &fixed);
	bool operator<=(const Fixed &fixed);
	bool operator==(const Fixed &fixed);
	bool operator!=(const Fixed &fixed);

	Fixed operator+(const Fixed &fixed);
	Fixed operator-(const Fixed &fixed);
	Fixed operator*(const Fixed &fixed);
	Fixed operator/(const Fixed &fixed);

	Fixed operator--(void);
	Fixed operator--(int);
	Fixed operator++(void);
	Fixed operator++(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);

	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

  private:
	int _value;
	static const int _fracBits;
};

ostream &operator<<(ostream &o, Fixed const &rhs);

#endif /* ********************************************************** Fixed_H */