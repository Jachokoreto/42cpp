#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "styling.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif


class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &operator=( WrongAnimal const & rhs );

		void makeSound(void) const;
		std::string getType(void) const;

	protected:
		
		std::string	type;

	private:

};

std::ostream &operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ********************************************************** WrongAnimal_H */