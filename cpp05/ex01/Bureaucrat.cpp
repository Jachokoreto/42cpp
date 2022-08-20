#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name("foo"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src.getName()), _grade(src.getGrade()) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	// (void)rhs;
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::gradeDecr(void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << this->_name << " grade decreased" << std::endl;
}

void Bureaucrat::gradeIncr(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << this->_name << " grade increased" << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
		form.beSigned(*this);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(_grade);
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is smaller than 1, too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is bigger than 150, too low");
}

/* ************************************************************************** */