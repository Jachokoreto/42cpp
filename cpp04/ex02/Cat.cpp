#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : AAnimal("Cat")
{
	_brain = new Brain();
	msg::constructor("Cat", "default");
}

Cat::Cat( const Cat & src ) : AAnimal(src)
{
	_brain = new Brain();
	_brain->copyIdeas(*src._brain);
	msg::constructor("Cat", "copy constuctor");
}

Cat::Cat(std::string idea) : AAnimal("Cat")
{
	_brain = new Brain();
	_brain->setIdeas(idea);
	msg::constructor("Cat", "string for idea");
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	msg::destructor("Cat");
	delete(_brain);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		*this->_brain = *rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const
{
	std::cout << PNK "😺 Cat\t: nyan-nyan ~ "
			  << *getBrain()->getIdeas()
			  <<  RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain *Cat::getBrain() const
{
	return _brain;
}

/* ************************************************************************** */