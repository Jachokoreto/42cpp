#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <class T>
class Array
{

	public:

		Array();
		Array(unsigned int);
		Array( Array const & src );
		~Array();

		Array &		operator=( Array const & rhs );

	private:
		T *elements;

};

std::ostream &			operator<<( std::ostream & o, Array const & i );

#endif /* *********************************************************** ARRAY_H */