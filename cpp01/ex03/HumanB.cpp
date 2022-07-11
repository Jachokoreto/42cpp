/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:11:54 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 21:20:46 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(string name):_name(name){}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanB::attack(void)
{
	cout << this->getName() << " attacks with their " << this->getWeapon() << endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

string	HumanB::getWeapon(void)
{
	return (this->_weapon->getType());
}


void	HumanB::setName(string name)
{
	this->_name = name;
}

string	HumanB::getName(void)
{
	return (this->_name);
}

/* ************************************************************************** */
