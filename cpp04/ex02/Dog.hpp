#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"
# include "Message.hpp"

class Dog: public AAnimal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();
		Dog(std::string idea);

		Dog &		operator=( Dog const & rhs );

		void makeSound(void) const;
		Brain *getBrain() const;

	private:
		Brain *_brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */