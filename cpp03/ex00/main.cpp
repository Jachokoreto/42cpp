
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:41 by jatan             #+#    #+#             */
/*   Updated: 2022/07/15 13:41:25 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1("BL1");
	ClapTrap ct2("BL2");

	cout << endl

		 << " == Testing BL1's and BL2's attack and repair ability ==" << endl;
	ct1.setAttackDmg(2);
	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());
	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());
	ct2.beRepaired(2);

	cout << endl
		 << " == Testing BL1 energy points ==" << endl;
	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");
	ct2.takeDamage(ct1.getAttackDmg());

	ct1.attack("BL2");

	ct1.attack("BL2");

	return 0;
}