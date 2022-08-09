#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "styling.hpp"
# include "Message.hpp"

class AAnimal
{

	public:

		AAnimal();
		AAnimal(std::string type);
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &operator=( AAnimal const & rhs );

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		
		std::string	type;

	private:

};

std::ostream &operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */