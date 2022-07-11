/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:41 by jatan             #+#    #+#             */
/*   Updated: 2022/07/10 21:33:08 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	// std::string temp[] =
	// {
	this->prompt[0] = "firstname";
	this->prompt[1] = "lastname";
	this->prompt[2] = "nickname";
	this->prompt[3] = "phonenumber";
	this->prompt[4] = "darksecret";
	// };

	// for (int i = 0; i < 5; i++)
	// 	this->prompt[i] = temp[i];
}

Contact::~Contact(void)
{
}

bool Contact::setContact(std::istream &input)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter " << prompt[i] << " : ";
		std::getline(input, this->fields[i]);
		if (this->fields[i].empty())
		{
			std::cout << "Empty field not allowed!" << std::endl;
			while (i >= 0)
				this->fields[i--].clear();
			break;
		}
	}
	if (this->fields[firstName].empty())
	{
		std::cout << RED << "New contact not saved!" << RESET << std::endl
				  << std::endl;
		return false;
	}
	else
	{
		std::cout << GRN << "New contact saved --> " << this->fields[firstName] << RESET << std::endl
				  << std::endl;
		return true;
	}
}

void Contact::displayContact(void)
{
	std::cout << YLW "Displaying info for " << this->fields[firstName] << RESET << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << this->prompt[i] << " : " << this->fields[i] << std::endl;
}

std::string Contact::truncate(std::string str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 3) + "...");
	return (str);
}

void Contact::displaySearch(int index)
{
	std::cout << "|"
			  << std::setw(10) << index + 1 << SEP
			  << std::setw(10) << truncate(this->fields[firstName], 10) << SEP
			  << std::setw(10) << truncate(this->fields[lastName], 10) << SEP
			  << std::setw(10) << truncate(this->fields[nickname], 10) << SEP << std::endl;
}
