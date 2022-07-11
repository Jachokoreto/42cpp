/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:41 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 02:01:03 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	count = 0;
	index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::runOption(int i)
{
	void (PhoneBook::*t_fptr[])(void) =
		{
			&PhoneBook::_add,
			&PhoneBook::_search,
			&PhoneBook::_fillDummy,
		};
	(this->*t_fptr[i])();
}

void PhoneBook::_add(void)
{
	std::cout << BLU "ADD MODE" RESET << std::endl;
	if (contact[this->index].setContact(std::cin) == true)
	{
		if (this->count < 8)
			count++;
		if (this->index == 7)
			this->index = 0;
		else
			this->index++;
	}
}

void PhoneBook::_search(void)
{
	int i, sIndex;
	std::string input;

	std::cout << BLU "SEARCH MODE" RESET << std::endl
			  << std::string(4 * (10 + 3), '-') << std::endl
			  << "|"
			  << std::setw(10) << "Index" << SEP
			  << std::setw(10) << "Firstname" << SEP
			  << std::setw(10) << "Lastname" << SEP
			  << std::setw(10) << "Nickname" << SEP << std::endl
			  << std::string(4 * (10 + 3), '-') << std::endl;

	i = -1;
	while (++i < this->count)
		contact[i].displaySearch(i);

	std::cout << std::string(4 * (10 + 3), '-') << std::endl
			  << "Select index : ";

	std::getline(std::cin, input);
	try
	{
		sIndex = std::stoi(input);
	}
	catch (std::invalid_argument)
	{
		std::cout << RED "Bad input!" RESET << std::endl;
		return;
	}
	if (sIndex - 1 < count)
		contact[sIndex - 1].displayContact();
	else
		std::cout << RED "Selection out of range" RESET << std::endl;
	std::cout << std::endl;
}

void PhoneBook::_fillDummy(void)
{
	std::ifstream iFile;
	std::string input;
	int num;

	std::cout << YLW "Filling up phonebook with dummy data..." RESET << std::endl
			  << "How many contacts would you like to fill? (1 ~ 8) : ";
	std::getline(std::cin, input);
	num = std::stoi(input);
	iFile.open("./dummy.txt");
	for (int i = 0; i < num; i++)
	{
		if (this->contact[this->index].setContact(iFile) == true)
		{
			if (this->count < 8)
				count++;
			if (this->index == 7)
				this->index = 0;
			else
				this->index++;
		}
	}
	iFile.close();
}

void PhoneBook::_displayAll(void)
{
	for (int i = 0; i < this->count; i++)
		this->contact[i].displayContact();
}