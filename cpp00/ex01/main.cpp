/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:50:39 by jatan             #+#    #+#             */
/*   Updated: 2022/07/10 22:56:11 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"
#include "styling.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	PhoneBook phonebook;
	string input;
	string tmp;

	tmp = "ASF";

	cout << GRN "PHONEBOOK DESU" RESET << endl;

	while (1)
	{
		input = "";
		cout << "Options: ADD, SEARCH, EXIT" << endl;
		cout << "Select an option : ";
		std::getline(std::cin, input);
		cout << std::endl;
		if (input == "ADD" || input == "SEARCH" || input == "FILL")
			phonebook.runOption(tmp.find(input[0]));
		else if (input == "EXIT")
		{
			cout << "Exiting..." << endl;
			break;
		}
		else
			cout << RED "Incorrect input!" RESET << endl
				 << endl;
	}
}