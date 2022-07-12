/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:25:33 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 23:30:25 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	string	input;
	Harl	harl;

	if (argc != 2)
		return (1);
	input = string(argv[1]);
	if (input == "DEBUG" || input == "INFO" 
		|| input == "WARNING" || input == "ERROR")
	{
		harl.complain(input);
	}
}