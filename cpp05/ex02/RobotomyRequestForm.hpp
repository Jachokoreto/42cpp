#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		
		void	execute(Bureaucrat &b);

		std::string getTarget(void) const;

	private:
		const std::string _target;

};

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* RobotomyRequestForm_H */