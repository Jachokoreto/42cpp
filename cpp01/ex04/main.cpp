/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:25:33 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 22:51:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
	ifstream	iFile;
	ofstream	oFile;
	string		filename, s1, s2, input;
	size_t		fPos;

	if (argc != 4)
		return (1);
	filename = string(argv[1]);
	iFile.open(filename.c_str());
	if (iFile.is_open() == false)
		cout << "failed to open iFile" << endl;

	oFile.open((filename + ".replace").c_str());
	if (oFile.is_open() == false)
		cout << "failed to open oFile" << endl;

	s1 = string(argv[2]);
	s2 = string(argv[3]);
	while (1)
	{
		getline(iFile, input);
		if (input.empty())
			break;
		fPos = 0;
		while (fPos != string::npos)
		{
			fPos = input.find(s1, fPos);
			if (fPos != string::npos)
			{
				input.erase(fPos, s1.length());
				input.insert(fPos, s2);
				fPos += s2.length();
			}
		}
		oFile << input << endl;
	}
	iFile.close();
	oFile.close();
}