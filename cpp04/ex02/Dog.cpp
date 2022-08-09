#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): AAnimal("Dog")
{
	msg::constructor("Dog", "default");
	_brain = new Brain();
}

Dog::Dog( const Dog & src ) : AAnimal(src)
{
	_brain = new Brain();
	_brain->copyIdeas(*src._brain);
	msg::constructor("Dog", "copy construtor");
}

Dog::Dog(std::string idea) : AAnimal("Dog")
{
	_brain = new Brain();
	_brain->setIdeas(idea);
	msg::constructor("Dog", "string for idea");
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	msg::destructor("Dog");
	delete(_brain);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		*this->_brain = *rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const
{
	std::cout << YLW "🐶 Dog\t: wan-wan ~ "
			  << *getBrain()->getIdeas()
			  << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Dog::getBrain() const
{
	return _brain;
}

/* ************************************************************************** */