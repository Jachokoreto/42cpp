#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure")
{
	std::cout << "\e[0;33mDefault Constructor called of Cure\e[0m" << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of Cure\e[0m" << std::endl;
}

// Destructor
Cure::~Cure()
{
	std::cout << "\e[0;31mDestructor called of Cure\e[0m" << std::endl;
}

// Operators
Cure &Cure::operator=(const Cure &assign)
{
	// (void)assign;
	AMateria::operator=(assign);
	return *this;
}

// Methods
AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
