#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int Animal::_fracBits = 8;

Animal::Animal(void) : _value(0)
{
	// cout << "Default constructor called" << endl;
}

Animal::Animal(const Animal &Animal)
{
	// cout << "Copy constructor called" << endl;
	this->_value = Animal.getRawBits();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	// cout << "Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const &rhs)
{
	// cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Animal::setRawbits(int const raw)
{
	this->_value = raw;
	// cout << "setRawBits member function called" << endl;
}

int Animal::getRawBits(void) const
{
	// cout << "getRawBits  member function called" << endl;
	return (this->_value);
}

/* ************************************************************************** */