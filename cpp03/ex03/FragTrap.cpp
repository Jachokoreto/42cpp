#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(void) : ClapTrap("", 100, 100, 30)
{
	cout << "debug: FragTrap::Default constructor called" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name, 100, 100, 30)
{
	cout << "debug: FragTrap::String constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	cout << "debug: FragTrap::Copy constructor called" << endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	cout << "debug: FragTrap::Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	cout << "debug: FragTrap::Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->ClapTrap::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	cout << this->getName() << " is requesting for some high fives!!" << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */