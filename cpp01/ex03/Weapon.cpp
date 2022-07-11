#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


Weapon::Weapon(string type)
{
	this->setType(type);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Weapon &				Weapon::operator=( Weapon const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Weapon const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

string &Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(string type)
{
	this->_type = type;
}

 
/* ************************************************************************** */