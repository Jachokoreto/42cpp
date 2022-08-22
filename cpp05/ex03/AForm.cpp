#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): _name("foo"), _isSigned(false), _reqGradeToSign(150), _reqGradeToExec(150)
{
}

AForm::AForm(std::string name, int sign, int exec):
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

AForm::AForm( const AForm & src ):
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_reqGradeToSign(src.getReqGradeToSign()),
	_reqGradeToExec(src.getReqGradeToExec())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/**
 * @brief Prints all the AForm's inAFormation
 */
std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	msg::info("Form information");
	o << "Name: " << i.getName() << std::endl
	  << "Signed status: " << std::boolalpha << i.getIsSigned() << std::endl
	  << "Required grade to sign: " << i.getReqGradeToSign() << std::endl
	  << "Required grade to execute: " << i.getReqGradeToExec() <<std::endl;

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::checkExec(Bureaucrat &b)
{
	if (this->getIsSigned() == false)
		throw NotSignedException();
	if (b.getGrade() > _reqGradeToExec)
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _reqGradeToSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getReqGradeToSign(void) const
{
	return (_reqGradeToSign);
}

int	AForm::getReqGradeToExec(void) const
{
	return (_reqGradeToExec);
}


/* ************************************************************************** */

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is smaller than 1, too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low, either bigger than 150 or lower than required grade");
}


const char *AForm::NotSignedException::what() const throw()
{
	return ("form is not signed, unable to process execute request");
}