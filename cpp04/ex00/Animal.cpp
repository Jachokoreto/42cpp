#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("animal")
{
	msg::constructor("Animal", "default");
}

Animal::Animal(std::string type): type(type)
{
	msg::constructor("Animal", "variable string = type");
}

Animal::Animal( const Animal & src )
{
	msg::constructor("Animal", "copy constructor");
	type = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	msg::destructor("Animal");
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const
{
	std::cout << BLU "🐵 Ani\t: uwu ~ " RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const
{
	return type;
}


/* ************************************************************************** */