/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:21:02 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 18:26:17 by jatan            ###   ########.fr       */
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

	cout << "Printing memory address..." << endl;
	cout << "Memory address of str : " << &str << endl;
	cout << "Memory address of sPtr : " << &str << endl;
	cout << "Memory address of sRef : " << &str << endl;
}