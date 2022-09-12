#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 50, 20)
{
	cout << "debug: ScavTrap::Default constructor called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name, 100, 50, 20)
{
	cout << "debug: ScavTrap::String constructor called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	cout << "debug: ScavTrap::Copy constructor called" << endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	cout << "debug: ScavTrap::Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	cout << "debug: ScavTrap::Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->ClapTrap::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const string &target)
{
	if (this->getHitPts() == 0)
		cout << "ScavTrap " << this->getName() << " is dying..." << endl;
	else if (this->getEnergyPts() == 0)
		cout << "ScavTrap " << this->getName() << " is tired..." << endl;
	else
	{
		cout << "ScavTrap " << this->getName()
			 << " attacks " << target
			 << ", causing " << this->getAttackDmg() << " points of damage!" << endl;
		this->setEnergyPts(this->getEnergyPts() - 1);
	}
}


void ScavTrap::guardGate(void)
{
	cout << this->getName() << " is now in Gate keeper mode" << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */