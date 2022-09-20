#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int n) : _maxNum(n)
{
}

Span::Span(const Span &rhs)
{
	*this = rhs;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
	// cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
	{
		this->_maxNum = rhs._maxNum;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void addNumber(int n){

};

int shortestSpan(void){

};

int longestSpan(void){

};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */