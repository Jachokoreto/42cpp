#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

#include "jttool.hpp"

void	test1(void)
{
	msg::annouceTest("Test 1", "Create forms by intern");

	Intern randomIntern;
	AForm *forms[4];

	forms[0] = randomIntern.makeForm("shrubbery creation", "home 1");
	forms[1] = randomIntern.makeForm("robotomy request", "Kitchen");
	forms[2] = randomIntern.makeForm("presidential pardon", "SirhCofe");
	forms[3] = randomIntern.makeForm("doggy adoption", "jac");

	for (int i = 0; i < (int)(sizeof(forms) / sizeof(forms[0])); i++)
	{
		if (forms[i] == NULL)
			continue;
		std::cout << *(forms[i]);
		delete(forms[i]);
	}
}

void	test2(void)
{
	msg::annouceTest("Test 2", " Sign and execute created forms by intern");

	Intern randomIntern;
	AForm *forms[4];
	Bureaucrat b;

	forms[0] = randomIntern.makeForm("shrubbery creation", "home 1");
	forms[1] = randomIntern.makeForm("robotomy request", "Kitchen");
	forms[2] = randomIntern.makeForm("presidential pardon", "SirhCofe");
	forms[3] = randomIntern.makeForm("doggy adoption", "jac");

	for (int i = 0; i < (int)(sizeof(forms) / sizeof(forms[0])); i++)
	{
		if (forms[i] == NULL)
			continue;
		b = Bureaucrat("tmp", forms[i]->getReqGradeToExec());
		std::cout << b << *(forms[i]);
		b.signForm(*forms[i]);
		b.executeForm(*forms[i]);
		delete(forms[i]);
	}
}

int	main(void)
{
	test1();
	test2();
	return (0);
}