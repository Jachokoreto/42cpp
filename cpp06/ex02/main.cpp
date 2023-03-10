#include <string>
#include <iostream>
#include "classes.hpp"
#include <stdint.h>
#include <cstdlib>
#include "jttool.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			return NULL;
			break;
	}
}

void identify(Base *p)
{
	Base *ptr;
	std::cout << "Identify with pointer\n";
	ptr = dynamic_cast<A*>(p);
	if (ptr != NULL)
		std::cout << GRN "its A " RESET << ptr << std::endl;
	else
		std::cout << "its not A! " << std::endl;
	ptr = dynamic_cast<B*>(p);
	if (ptr != NULL)
		std::cout << GRN "its B " RESET << ptr << std::endl;
	else
		std::cout << "its not B! " << std::endl;
	ptr = dynamic_cast<C*>(p);
	if (ptr != NULL)
		std::cout << GRN "its C " RESET << ptr << std::endl;
	else
		std::cout << "its not C! " << std::endl;

}

void identify(Base &p)
{
	std::cout << "\nIdentify with reference\n";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << GRN "its A " RESET << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "its not A " << std::endl;
		// std::cerr << e.what() << '\n';
	}
	try
	{
		B &a = dynamic_cast<B &>(p);
		std::cout << GRN "its B " RESET << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "its not B " << std::endl;
		// std::cerr << e.what() << '\n';
	}
	try
	{
		C &a = dynamic_cast<C &>(p);
		std::cout << GRN "its C " RESET << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "its not C " << std::endl;
		// std::cerr << e.what() << '\n';
	}
}


int main(void)
{

	Base *base;

	for (int i = 0; i < 10; i++)
	{
		msg::info("Generating class...");
		base = generate();
		identify(base);
		identify(*base);
		delete(base);
	}
	return (0);
}