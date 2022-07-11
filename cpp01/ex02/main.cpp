/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:21:02 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 18:31:43 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string str = "HI THIS IS BRAIN";
	
	string *sPtr = &str;
	string &sRef = str;

	cout << "Printing memory address..." << endl
		 << "Memory address of str : " << &str << endl
		 << "Memory address of sPtr : " << &sPtr << endl
		 << "Memory address of sRef : " << &sRef << endl << endl
		 << "Printing value..." << endl
		 << "Value of str : " << str << endl
		 << "Value of sPtr : " << *sPtr << endl
		 << "Value of sRef : " << sRef << endl;
}