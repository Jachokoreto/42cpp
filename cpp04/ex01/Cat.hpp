#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"
# include "Message.hpp"

class Cat: public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();
		Cat(std::string idea);

		Cat &operator=( Cat const & rhs );

		void makeSound(void) const;
		Brain *getBrain() const;
	
	private:
		Brain *_brain;

};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */