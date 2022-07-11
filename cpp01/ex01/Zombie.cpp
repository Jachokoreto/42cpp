/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:59:46 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 17:52:19 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	
}

Zombie::Zombie(string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	cout << this->_name << " removed..." << endl;
}

void Zombie::announce(void)
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void Zombie::setName(string name)
{
	this->_name = name;
}