#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ClapTrap a;
	ClapTrap b(a);
	ClapTrap c("M4RV1N");

	cout << "[DEFAULT] will now attack M4RV1N 10 times. The 11th will fail due to no energy!" << endl;
	cout << endl;

	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");
	a.attack("M4RV1N");

	// This will fail
	a.attack("M4RV1N");

	cout << endl;
	cout << endl;

	cout << "Let's assume some fking EMP just destroyed this lil bro" << endl;
	c.takeDamage(1000);

	// This should not take damage anymore
	c.takeDamage(3);

	b.beRepaired(1);
	b.beRepaired(2);
	c.beRepaired(3);

	cout << endl;
	cout << "SCAVTRAP TESTS" << endl;
	cout << endl;

	ScavTrap dflt2;
	ScavTrap pete("P3T3");
	ScavTrap pete2(pete);
	ScavTrap equal;

	cout << "=================================" << endl;
	cout << "Original P3T3" << endl;
	cout << "Name: " << pete.getName() << endl;
	cout << "Hp: " << pete.getHitPts() << endl;
	cout << "Energy: " << pete.getEnergyPts() << endl;
	cout << "Atk: " << pete.getAttackDmg() << endl;
	cout << "=================================" << endl;

	cout << endl;

	cout << "=================================" << endl;
	cout << "COPIED P3T3" << endl;
	cout << "Name: " << pete2.getName() << endl;
	cout << "Hp: " << pete2.getHitPts() << endl;
	cout << "Energy: " << pete2.getEnergyPts() << endl;
	cout << "Atk: " << pete2.getAttackDmg() << endl;
	cout << "=================================" << endl;

	cout << endl;

	pete2.attack("DONKEY");
	pete2.attack("DONKEY");
	pete2.attack("DONKEY");

	cout << "=================================" << endl;
	cout << "Default" << endl;
	cout << "Name: " << equal.getName() << endl;
	cout << "Hp: " << equal.getHitPts() << endl;
	cout << "Energy: " << equal.getEnergyPts() << endl;
	cout << "Atk: " << equal.getAttackDmg() << endl;
	cout << "=================================" << endl;

	cout << endl;
	equal = pete2;

	cout << "=================================" << endl;
	cout << "Default Copied" << endl;
	cout << "Name: " << equal.getName() << endl;
	cout << "Hp: " << equal.getHitPts() << endl;
	cout << "Energy: " << equal.getEnergyPts() << endl;
	cout << "Atk: " << equal.getAttackDmg() << endl;
	cout << "=================================" << endl;

	cout << endl;

	equal.guardGate();

	cout << endl;

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
