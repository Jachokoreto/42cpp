#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", 72, 45), _target("unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm(src), _target(src.getTarget())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void)rhs;
	if ( this != &rhs )
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
// {
// 	o << (AForm &)i 
// 	  << "Target: " << i.getTarget() << std::endl;
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * @brief Makes some drilling noises. Then, informs that <target> has been robotomized
		  successfully 50% of the time. Otherwise, informs that the robotomy failed.
 */
void RobotomyRequestForm::execute(Bureaucrat &b)
{
	std::string status;
	this->AForm::checkExec(b); // this will throw exception if requirement not met
	std::cout << IDG "Bzzzzzz bzzzzz..." << std::endl;
	if (rand() % 100 < 50)
	{
		std::cout << GRN << this->_target << " has been robotomized successfully"
				  << RESET << std::endl;
	}
	else
	{
		std::cout << RED "Technical failure! Failed to robotomized " << this->_target
				  << RESET << std::endl;
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

/* ************************************************************************** */