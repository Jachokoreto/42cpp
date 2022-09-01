/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:21:02 by jatan             #+#    #+#             */
/*   Updated: 2022/08/31 17:30:46 by jatan            ###   ########.fr       */
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
		 << "==== Get memory address of str ==== " << endl 
		 << "Using variable\t\t: " << &str << endl
		 << "Using pointer,[sPtr]\t: " << sPtr << endl
		 << "Using reference,[&sRef]\t: " << &sRef << endl << endl

		 << "=== Get str ====" << endl
		 << "Using str\t\t: " << str << endl
		 << "Using sPtr,[*sPtr]\t: " << *sPtr << endl
		 << "Using sRef,[sRef]\t: " << sRef << endl;
}