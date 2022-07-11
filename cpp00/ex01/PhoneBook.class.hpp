/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:48 by jatan             #+#    #+#             */
/*   Updated: 2022/07/10 22:45:09 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"
#include "styling.hpp"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);
	void runOption(int);

  private:
	int count;
	int index;
	Contact contact[8];
	void _add(void);
	void _search(void);
	void _fillDummy(void);
	void _displayAll(void);
};

#endif