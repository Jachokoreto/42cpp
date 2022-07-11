/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:11:54 by jatan             #+#    #+#             */
/*   Updated: 2022/07/11 21:09:52 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(string name, Weapon &weapon):_name(name),_weapon(weapon)
{
	
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanA::attack(void)
{
	cout << this->getName() << " attacks with their " << this->getWeapon() << endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

string	HumanA::getWeapon(void)
{
	return (this->_weapon.getType());
}


void	HumanA::setName(string name)
{
	this->_name = name;
}

string	HumanA::getName(void)
{
	return (this->_name);
}

/* ************************************************************************** */