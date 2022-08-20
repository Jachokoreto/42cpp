#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const & rhs );

		void gradeIncr(void);
		void gradeDecr(void);

		std::string getName(void) const;
		int getGrade(void) const;


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

	private:
		std::string const _name;
		int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */