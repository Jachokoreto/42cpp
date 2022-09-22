#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(const Cure &copy);
		
		// Destructor
		~Cure();
		
		// Operators
		Cure & operator=(const Cure &assign);

		// Methods
		AMateria *clone() const;
		void use(ICharacter &target);

		
	private:
		
};

#endif