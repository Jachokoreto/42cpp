#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name("foo"), _isSigned(false), _reqGradeToSign(150), _reqGradeToExec(150)
{
}

Form::Form(std::string name, int sign, int exec):
	_name(name),
	_isSigned(false),
	_reqGradeToSign(sign),
	_reqGradeToExec(exec)
{
	if (_reqGradeToSign > 150 || _reqGradeToExec > 150)
		throw GradeTooLowException();
	if (_reqGradeToSign < 1 || _reqGradeToExec < 1)
		throw GradeTooHighException();
}

Form::Form( const Form & src ):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_reqGradeToSign(src.getReqGradeToSign()),
	_reqGradeToExec(src.getReqGradeToExec())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/**
 * @brief Prints all the form's information
 */
std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Name: " << i.getName() << std::endl
	  << "Signed status: " << i.getIsSigned() << std::endl
	  << "Required grade to sign: " << i.getReqGradeToSign() << std::endl
	  << "Required grade to execute: " << i.getReqGradeToExec() <<std::endl;

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _reqGradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getReqGradeToSign(void) const
{
	return (_reqGradeToSign);
}

int	Form::getReqGradeToExec(void) const
{
	return (_reqGradeToExec);
}


/* ************************************************************************** */

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is smaller than 1, too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low, either bigger than 150 or lower than required grade");
}