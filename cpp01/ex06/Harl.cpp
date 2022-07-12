/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:57:56 by jatan             #+#    #+#             */
/*   Updated: 2022/07/12 10:23:10 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "styling.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::complain(string level)
{
	string tmp = "DIWE";
	int levelNum = tmp.find(level[0]);

	void (Harl::*t_fptr[])(void) =
		{
			&Harl::_debug,
			&Harl::_info,
			&Harl::_warning,
			&Harl::_error,
		};
	for (int i = 0; i < 4; i++)
	{
		if (i >= levelNum)
			(this->*t_fptr[i])();
	}
}

void	Harl::_debug(void)
{
	cout << PNK "[ DEBUG ]" RESET << endl
		 << ">> Some random text for debug"<< endl << endl;

}

void	Harl::_info(void)
{
		cout << BLU "[ INFO ]" RESET << endl
		 << ">> Some random text for info"<< endl << endl;
}

void	Harl::_warning(void)
{
		cout << YLW "[ WARNING ]" RESET << endl
		 << ">> Some random text for warning"<< endl << endl;
}

void	Harl::_error(void)
{
		cout << RED "[ ERROR ]" RESET << endl
		 << ">> Some random text for error"<< endl << endl;
}