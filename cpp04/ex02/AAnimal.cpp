#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(): type("animal")
{
	msg::constructor("AAnimal", "default");
}

AAnimal::AAnimal(std::string type): type(type)
{
	msg::constructor("AAnimal", "variable string = type");
}

AAnimal::AAnimal( const AAnimal & src )
{
	msg::constructor("AAnimal", "copy constructor");
	type = src.getType();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	msg::destructor("AAnimal");
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AAnimal::makeSound(void) const
{
	std::cout << BLU "🐵 Ani\t: uwu ~ " RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const
{
	return type;
}


/* ************************************************************************** */