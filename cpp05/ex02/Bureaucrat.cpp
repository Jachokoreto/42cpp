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
	msg::info("Bureaucrat information");
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
	std::cout << this->_name << "'s grade decreased-- -> "
			  << this->getGrade() << std::endl;
}

void Bureaucrat::gradeIncr(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << this->_name << "'s grade increased++ -> "
			  << this->getGrade() << std::endl;
}

//
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		msg::info("Trying to sign " + form.getName());
		form.beSigned(*this);
		std::cout << YLW "ACTION : "
				  << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
					<< " beacause " << e.what() << std::endl;
		throw e;
	}
}

bool Bureaucrat::executeForm(AForm &form)
{
	try
	{
		msg::info("Trying to execute " + form.getName());
		form.execute(*this);
		std::cout << YLW "ACTION : "
				  << this->_name << " executed " << form.getName() << RESET << std::endl;
	}
	catch(const AForm::NotSignedException& e)
	{	
		std::cout << "Can't execute " << form.getName() << " because "
				  << e.what() << std::endl;
		return false;
	}
	catch(const AForm::GradeTooLowException& e)
	{	
		std::cout << "Can't execute " << form.getName() << " because "
				  << e.what() << std::endl;
		return false;
	}
	return true;
	
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