#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	DiamondTrap fT1("Diaamon");

	cout << "=================================" << endl;
	cout << "DiamondTrap" << endl;
	cout << "Name: " << fT1.getName() << endl;
	cout << "Hp: " << fT1.getHitPts() << endl;
	cout << "Energy: " << fT1.getEnergyPts() << endl;
	cout << "Atk: " << fT1.getAttackDmg() << endl;
	cout << "=================================" << endl;

	fT1.highFivesGuys();
	fT1.whoAmI();
	cout << endl;

	return 0;
}
