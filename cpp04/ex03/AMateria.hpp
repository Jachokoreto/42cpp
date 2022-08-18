#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string type;

	public:

		AMateria();
		AMateria( AMateria const & src );
		~AMateria();
		AMateria(std::string const & type);

		AMateria &		operator=( AMateria const & rhs );

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; // return a new instance of the same type
		
		// virtual void use(ICharacter& target); 
			// • Ice: "* shoots an ice bolt at <name> *"
			// • Cure: "* heals <name>’s wounds *"
};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */