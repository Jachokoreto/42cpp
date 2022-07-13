/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:56:36 by jatan             #+#    #+#             */
/*   Updated: 2022/07/13 15:05:25 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Fixed
{

  public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawbits(int const raw);

  private:
	int _value;
	static const int _fBits;
};

#endif /* ********************************************************** Fixed_H */