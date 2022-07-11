/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:44:52 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 18:17:49 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zArr;
	int		num = 3;
	string	name = "Walker";



	zArr = zombieHorde(num, name);
	for (int i = 0; i < num; i++)
	{
		cout << i << " : ";
		zArr[i].announce();
	}
	delete [] zArr;
	return (0);
}

// https://github.com/qingqingqingli/CPP/wiki/Module01