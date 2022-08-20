#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{

	public:

		Form();
		Form(std::string name, int sign, int exec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void	beSigned(Bureaucrat &b);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getReqGradeToSign(void) const;
		int			getReqGradeToExec(void) const;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;

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

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */