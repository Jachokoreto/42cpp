#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

#include "Message.hpp"

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		Brain(std::string ideas[100]);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);
		

		// Getter & Setter
		std::string *getIdeas() const;
		void setIdeas(std::string);
		void copyIdeas(const Brain &copy);

		
	protected:
		std::string ideas[100];
};

#endif