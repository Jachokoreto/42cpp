#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

#include "jttool.hpp"

void	test1(void)
{
	msg::annouceTest("Test 1", "Create forms");

	AForm *forms[3];

	forms[0] = new ShrubberyCreationForm();
	forms[1] = new RobotomyRequestForm();
	forms[2] = new PresidentialPardonForm();

	for (int i = 0; i < 3; i++)
	{
		std::cout << *(forms[i]);
		delete(forms[i]);
	}
}

void	tryExecuteForm(AForm &form, Bureaucrat &b)
{
	if (b.executeForm(form) == false)
	{
		if (form.getIsSigned() == false)
		{
			while (b.getGrade() > form.getReqGradeToSign())
				b.gradeIncr(); // keep increasing grade until sign form requirement
			std::cout << b;
			b.signForm(form); 
		}
		if (b.executeForm(form) == true)
			return;
		while (b.getGrade() > form.getReqGradeToExec())
			b.gradeIncr(); // keep increasing grade until execute form requirement
		b.executeForm(form); // try execute form again
	}
}

void	test2(void)
{
	msg::annouceTest("Test 2", "Execute Shrubbery Creation Form");

	ShrubberyCreationForm form;
	int givenGrade = form.getReqGradeToSign() + 2;
	Bureaucrat a("MisterA", givenGrade);

	std::cout << a << form << std::endl;
	tryExecuteForm(form, a);
}

void	test3(void)
{
	msg::annouceTest("Test 3", "Execute Robotomy Request Form");

	RobotomyRequestForm form;
	int givenGrade = form.getReqGradeToSign() + 2;
	Bureaucrat a("MisterA", givenGrade);

	std::cout << a << form << std::endl;
	for (int i = 0; i < 10; i++)
		tryExecuteForm(form, a);
}

void	test4(void)
{
	msg::annouceTest("Test 4", "Execute Presidential Pardon Form");

	PresidentialPardonForm *form = new PresidentialPardonForm();
	int givenGrade = form->getReqGradeToSign() + 2;
	Bureaucrat a("MisterA", givenGrade);
	std::string target;

	for (int i = 0; i < 3; i++)
	{
		target = std::string("Pooh ") + std::string(1, '0' + i);
		delete(form);
		form = new PresidentialPardonForm(target);
		std::cout << "\nNew form with target: " << target << " created" << std::endl;
		tryExecuteForm(*form, a);
	}
	delete(form);
}

int	main(void)
{
	// test1();
	// test2();
	// test3();
	test4();
	return (0);
}