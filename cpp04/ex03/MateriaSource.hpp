#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		// Constructors
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		
		// Destructor
		~MateriaSource();
		
		// Operators
		MateriaSource & operator=(const MateriaSource &assign);

		// Methods
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &);
		
	private:
		AMateria *_storage[4];
};

#endif