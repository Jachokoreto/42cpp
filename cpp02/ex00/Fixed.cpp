/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:11:54 by jatan             #+#    #+#             */
/*   Updated: 2022/09/04 04:50:56 by jatan            ###   ########.fr       */
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

/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * ! --------------------------------- ACCESSOR ---------------------------------
 */

void Fixed::setRawbits(int const raw)
{
	this->_value = raw;
	cout << "setRawBits member function called" << endl;
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits  member function called" << endl;
	return (this->_value);
}

/* ************************************************************************** */