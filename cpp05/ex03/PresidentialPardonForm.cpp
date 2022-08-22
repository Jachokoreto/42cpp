#include "PresidentialPardonForm.hpp"
#include "jttool.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon Form", 25, 5), _target("unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm(src), _target(src.getTarget())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void)rhs;
	if ( this != &rhs )
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
// {
// 	o << (AForm &)i 
// 	  << "Target: " << i.getTarget() << std::endl;
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * @brief Informs that <target> has been pardoned by Zaphod Beeblebrox.
 */
void PresidentialPardonForm::execute(Bureaucrat &b)
{
	this->AForm::checkExec(b); // this will throw exception if requirement not met
	std::cout << PNK ">> Announcement <<" RESET << std::endl
			  << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

/* ************************************************************************** */