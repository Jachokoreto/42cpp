/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:11:54 by jatan             #+#    #+#             */
/*   Updated: 2022/07/13 21:12:44 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int Fixed::_fracBits = 8;

Fixed::Fixed(void) : _value(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int value)
{
	cout << "Int constructor called" << endl;
	this->_value = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	cout << "Float constructor called" << endl;
	this->_value = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	cout << "Copy constructor called" << endl;
	this->_value = fixed.getRawBits();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &Fixed::operator=(Fixed const &rhs)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
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
	cout << "setRawBits member function called" << endl;
}

int Fixed::getRawBits(void) const
{
	// cout << "getRawBits  member function called" << endl;
	return (this->_value);
}

/* ************************************************************************** */