#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "styling.hpp"
// # include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(std::string name, int sign, int exec);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		void	checkExec(Bureaucrat &b);
		void	beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat &b) = 0;

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getReqGradeToSign(void) const;
		int			getReqGradeToExec(void) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;


};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */