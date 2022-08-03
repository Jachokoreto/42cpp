#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(void)
{
	// cout << "Default constructor called" << endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// cout << "Copy constructor called" << endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
	// cout << "Destructor called" << endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &Point::operator=(Point const &rhs)
{
	// cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		return new Point(rhs.getX(), rhs.getY());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed Point::getX(void) const
{
	// cout << "getX  member function called" << endl;
	return (this->_x);
}

Fixed Point::getY(void) const
{
	// cout << "getY  member function called" << endl;
	return (this->_y);
}

/* ************************************************************************** */