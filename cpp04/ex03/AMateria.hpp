#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

#include "ICharacter.hpp"
class ICharacter;
class AMateria
{
	public:
		// Constructors
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string type);
		
		// Destructor
		virtual ~AMateria();
		
		// Operators
		AMateria & operator=(const AMateria &assign);
		
		// Getters / Setters
		std::string getType() const;

		// Methods
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
		
	protected:
		std::string _type;
		
};

#endif