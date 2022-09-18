#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shruberry Creation Form", 145, 137), _target("unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src.getTarget())
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
// {
// 	o << (AForm &)i
// 	  << "Target: " << i.getTarget() << std::endl;
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

/**
 * @brief Create a file <target>_shrubbery in the working directory, and writes ASCII trees
		  inside it.
 */
void ShrubberyCreationForm::execute(Bureaucrat &b)
{

	this->AForm::checkExec(b); // this will throw exception if requirement not met
	std::string std("_shrubbery");
	std::string fileName = this->_target + std;
	std::ofstream oFile(fileName.c_str());
	std::ifstream iFile("tree");
	oFile << iFile.rdbuf();
	std::cout << GRN "Planted a shrubbery at " << this->_target << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

/* ************************************************************************** */