#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	FragTrap fT1("Fraggie");

	cout << "=================================" << endl;
	cout << "FragTrap" << endl;
	cout << "Name: " << fT1.getName() << endl;
	cout << "Hp: " << fT1.getHitPts() << endl;
	cout << "Energy: " << fT1.getEnergyPts() << endl;
	cout << "Atk: " << fT1.getAttackDmg() << endl;
	cout << "=================================" << endl;

	fT1.highFivesGuys();
	cout << endl;

	return 0;
}
