/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:37 by jatan             #+#    #+#             */
/*   Updated: 2022/07/10 21:28:08 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include "styling.hpp"

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>

enum field
{
	firstName,
	lastName,
	nickname,
	pNum,
	darkScrt
};

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	bool setContact(std::istream &input);
	void displayContact(void);
	void displaySearch(int index);
	std::string truncate(std::string str, size_t width);

  private:
	std::string fields[5];
	std::string prompt[5];
};

#endif