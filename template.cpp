#include "Pizza.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const int Pizza::_fracBits = 8;

Pizza::Pizza(void) : _value(0)
{
	// cout << "Default constructor called" << endl;
}

Pizza::Pizza(const Pizza &Pizza)
{
	// cout << "Copy constructor called" << endl;
	this->_value = Pizza.getRawBits();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Pizza::~Pizza()
{
	// cout << "Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Pizza &Pizza::operator=(Pizza const &rhs)
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

/* ************************************************************************** */