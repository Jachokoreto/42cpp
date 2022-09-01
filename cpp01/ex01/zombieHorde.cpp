/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:32:11 by jatan             #+#    #+#             */
/*   Updated: 2022/08/31 17:24:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, string name)
{
	Zombie *zArray;

	zArray = new Zombie[n];

	for (int i = 0; i < n; i++)
		zArray[i].setName(name);

	return (zArray);
}