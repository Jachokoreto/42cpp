/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:25:33 by jatan             #+#    #+#             */
/*   Updated: 2022/09/01 15:02:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	sed(ifstream &iFile, char *strs[2], ofstream &oFile)
{
	size_t		fPos;
	string	input;
	
	while (1)
	{
		getline(iFile, input);
		if (iFile.eof() && input.empty())
			break;
		fPos = 0;
		while (fPos != string::npos)
		{
			fPos = input.find(string(strs[0]), fPos);
			if (fPos != string::npos)
			{
				input.erase(fPos, string(strs[0]).length());
				input.insert(fPos, string(strs[1]));
				fPos += string(strs[1]).length();
			}
		}
		oFile << input << endl;
		input.clear();
	}
}


int main(int argc, char **argv)
{
	ifstream	iFile;
	ofstream	oFile;
	string		filename;

	if (argc != 4)
	{
		cout << "Invalid argument" << endl;
		return (1);
	}
	filename = string(argv[1]);
	iFile.open(filename.c_str());
	if (iFile.is_open() == false)
	{
		cout << "failed to open iFile" << endl;
		return (1);
	}
	oFile.open((filename + ".replace").c_str());
	if (oFile.is_open() == false)
	{
		cout << "failed to open oFile" << endl;
		iFile.close();
		return (1);
	}

	
	sed(iFile, &(argv[2]), oFile);
	
	iFile.close();
	oFile.close();
}