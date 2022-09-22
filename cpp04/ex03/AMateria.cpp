#include "AMateria.hpp"

// Constructors
AMateria::AMateria()
{
	_type = "";
	std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	_type = copy.getType();
	std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of AMateria\e[0m" << std::endl;
}


// Destructor
AMateria::~AMateria()
{
	std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl;
}


// Operators
AMateria & AMateria::operator=(const AMateria &assign)
{
	_type = assign.getType();
	return *this;
}


// Getters / Setters
std::string AMateria::getType() const
{
	return _type;
}


// Methods
