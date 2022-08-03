#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(void) : _hitPts(10), _energyPts(10)
{
	cout << "debug: ClapTrap::Default constructor called" << endl;
}

ClapTrap::ClapTrap(string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	cout << "debug: ClapTrap::String constructor called" << endl;
}

ClapTrap::ClapTrap(string name, int hp, int ep, int ad) : _name(name), _hitPts(hp), _energyPts(ep), _attackDmg(ad)
{
	cout << "debug: ClapTrap::String constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	cout << "debug: ClapTrap::Copy constructor called" << endl;
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	cout << "debug: ClapTrap::Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	cout << "debug: Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const string &target)
{
	if (this->_hitPts == 0)
		cout << "ClapTrap " << this->_name << " is dying..." << endl;
	else if (this->_energyPts == 0)
		cout << "ClapTrap " << this->_name << " is tired..." << endl;
	else
	{
		cout << "ClapTrap " << this->_name
			 << " attacks " << target
			 << ", causing " << this->_attackDmg << " points of damage!" << endl;
		this->_energyPts--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPts != 0 && amount <= this->_hitPts)
	{
		cout << "ClapTrap " << this->_name
			 << " taken " << amount << " points of damage!"
			 << "(hp :" << this->_hitPts << " -> " << this->_hitPts - amount << ")"
			 << endl;
		this->_hitPts -= amount;
	}
	else
	{
		cout << "ClapTrap " << this->_name << " can't take it anymore..."
			 << endl;
		this->_hitPts = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	cout << "ClapTrap " << this->_name
		 << " recovered " << amount << " hp!"
		 << "(hp :" << this->_hitPts << " -> " << this->_hitPts + amount << ")"
		 << endl;
	this->_hitPts += amount;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitPts(void) const
{
	return (this->_hitPts);
}

int ClapTrap::getEnergyPts(void) const
{
	return (this->_energyPts);
}

int ClapTrap::getAttackDmg(void) const
{
	return (this->_attackDmg);
}

void ClapTrap::setAttackDmg(unsigned int amount)
{
	this->_attackDmg = amount;
}

/* ************************************************************************** */