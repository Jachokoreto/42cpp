#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "styling.hpp"
# include "Message.hpp"

class Animal
{

	public:

		Animal();
		Animal(std::string type);
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &operator=( Animal const & rhs );

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		
		std::string	type;

	private:

};

std::ostream &operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */