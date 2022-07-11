/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:44:52 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 17:02:54 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zPtr;

	zPtr = zPtr.newZombie("z1");
	Zombie::randomChump();
	return (0);
}

// https://github.com/qingqingqingli/CPP/wiki/Module01