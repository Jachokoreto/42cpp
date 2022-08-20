#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

#include "jttool.hpp"

void	test1(void)
{
	msg::annouceTest("Test 1", "Grade too high exception");
	int grade;

	grade = -1;
	while (1)
	{
		try
		{
			msg::info("Trying to initialize Form A with grade");
			std::cout << "Current grade = " << grade << std::endl;
			Form a("Form A", grade, grade);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << RED "Caught exception: " RESET << e.what() << std::endl;
			grade++;
			continue;
		}
		break;
	}
}

void	test2(void)
{
	msg::annouceTest("Test 2", "Grade too low exception");
	int grade;

	grade = 152;
	while (1)
	{
		try
		{
			msg::info("Trying to initialize Form A with grade");
			std::cout << "Current grade = " << grade << std::endl;
			Form a("Form A", grade, grade);
			std::cout << a << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << RED "Caught exception: " RESET << e.what() << std::endl;
			grade--;
			continue;
		}
		break;
	}
}

void	test3(void)
{
	msg::annouceTest("Test 3", "Sign form tests");

	Bureaucrat a("MisterA", 5);
	Form form("form 1", 2, 2);

	std::cout << form << std::endl;
	while(1)
	{
		msg::info("Try signing...");
		std::cout << a;
		a.signForm(form);
		if (form.getIsSigned() == true)
			break;
		else
			a.gradeIncr();
	}

}

int	main(void)
{
	test1();
	test2();
	test3();
	return (0);
}