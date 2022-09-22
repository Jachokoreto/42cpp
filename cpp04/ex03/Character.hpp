#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

# define MAX_SLOT 4

class Character: public ICharacter
{
	public:
		// Constructors
		Character(std::string _name);
		Character(const Character &copy);
		
		// Destructor
		~Character();
		
		// Operators
		Character & operator=(const Character &assign);
		
		// Getters / Setters
		std::string &getName() const;

		// Methods
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		
	private:
		std::string &_name;
		AMateria *_inventory[MAX_SLOT];
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Character &object);

#endif