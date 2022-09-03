/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:56:36 by jatan             #+#    #+#             */
/*   Updated: 2022/09/04 04:53:19 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * Orthodox canonical form requires the followings 4 functions:
 */
class Fixed
{
public:
	Fixed(void);						  // Default constructor
	Fixed(const Fixed &fixed);			  // Copy constructor
	Fixed &operator=(const Fixed &fixed); // Copy assignment constructor
	~Fixed(void);						  // Destructor

	int getRawBits(void) const;		// * accessors -> get
	void setRawbits(int const raw); // * accessors -> set

private:
	int _value;
	static const int _fracBits;
};

#endif /* ********************************************************** Fixed_H */