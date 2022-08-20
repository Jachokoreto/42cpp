#include "Bureaucrat.hpp"
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
			msg::info("Trying to initialize Mister A with grade");
			std::cout << "Current grade = " << grade << std::endl;
			Bureaucrat a("Mister A", grade);
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
			msg::info("Trying to initialize Mister A with grade");
			std::cout << "Current grade = " << grade << std::endl;
			Bureaucrat a("Mister A", grade);
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
	msg::annouceTest("Test 3", "Increment and decrement tests");

	Bureaucrat a("a", 148);
	
	while(1)
	{
		try
		{
			msg::info("decrementing...");
			a.gradeDecr();
			std::cout << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED "Caught exception: " RESET << e.what() << std::endl;
			break;
		}
		continue;
	}

	a = Bureaucrat("b", 2);
	while(1)
	{
		try
		{
			msg::info("incrementing...");
			a.gradeIncr();
			std::cout << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED "Caught exception: " RESET << e.what() << std::endl;
			break;
		}
		continue;
	}
}

int	main(void)
{
	test1();
	test2();
	test3();
	return (0);
}