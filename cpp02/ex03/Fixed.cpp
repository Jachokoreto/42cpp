/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:11:54 by jatan             #+#    #+#             */
/*   Updated: 2022/07/14 00:23:18 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int Fixed::_fracBits = 8;

Fixed::Fixed(void) : _value(0)
{
	// cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int value)
{
	// cout << "Int constructor called" << endl;
	this->_value = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	// cout << "Float constructor called" << endl;
	this->_value = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	// cout << "Copy constructor called" << endl;
	this->_value = fixed.getRawBits();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	// cout << "Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	// cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &fixed)
{
	if (this->getRawBits() > fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &fixed)
{
	if (this->getRawBits() < fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed &fixed)
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &fixed)
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &fixed)
{
	if (this->getRawBits() == fixed.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator!=(const Fixed &fixed)
{
	if (this->getRawBits() != fixed.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed res;

	res._value = (this->_value + fixed._value);
	return (res);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed res;

	res._value = (this->_value - fixed._value);
	return (res);
}

/**
 * Fixed point multiplication
 */

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed res;

	res._value = (this->_value * fixed._value) >> _fracBits;
	return (res);
}

// https://sestevenson.wordpress.com/fixed-point-division-of-two-q15-numbers/

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed res;

	res._value = ((this->_value << this->_fracBits) / fixed._value);
	return (res);
}

Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/**
 *  An overload of the insertion («) operator that inserts a floating-point representation
	of the fixed-point number into the output stream object passed as parameter.
*/

ostream &operator<<(ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * I did some searching online and found this: "To represent a negative exponent. 
 * All you have to do is divide 1 over the positive exponent. Ex: 6^-2 = 1/(6^2)."
 * 
 */

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << _fracBits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> _fracBits);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Fixed::setRawbits(int const raw)
{
	this->_value = raw;
	// cout << "setRawBits member function called" << endl;
}

int Fixed::getRawBits(void) const
{
	// cout << "getRawBits  member function called" << endl;
	return (this->_value);
}

/* ************************************************************************** */