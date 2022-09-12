#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(void)
{
	cout << "debug: DiamondTrap::Default constructor called" << endl;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name, 100, 50, 30)
{
	cout << "debug: DiamondTrap::String constructor called" << endl;
	this->_name = name;
	this->setName(name + "_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
	(void)rhs;
	cout << "debug: DiamondTrap::Copy constructor called" << endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	cout << "debug: DiamondTrap::Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	cout << "debug: DiamondTrap::Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->ClapTrap::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::attack(const string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	cout << "You asked who am I??" << endl
		 << "My name: " << this->_name << endl
		 << "ClapTrap name: " << getName() << endl
		 << "Hit points: " << getHitPts() << endl
		 << "Energy points: " << getEnergyPts() << endl
		 << "Attack damage: " << getAttackDmg() << endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */