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
	std::cout << "Identify with pointer\t";
	ptr = dynamic_cast<A*>(p);
	if (ptr != NULL)
		std::cout << "its A " << p << std::endl;
	ptr = dynamic_cast<B*>(p);
	if (ptr != NULL)
		std::cout << "its B " << p << std::endl;
	ptr = dynamic_cast<C*>(p);
	if (ptr != NULL)
		std::cout << "its C " << p << std::endl;

}

void identify(Base &p)
{
	std::cout << "Identify with reference\t";
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "its A " << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		B &a = dynamic_cast<B &>(p);
		std::cout << "its B " << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		C &a = dynamic_cast<C &>(p);
		std::cout << "its C " << &a << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
	}
}


int main(void)
{

	Base *base;

	for (int i = 0; i < 10; i++)
	{
		msg::info("Generating...");
		base = generate();
		identify(base);
		identify(*base);
		delete(base);
	}
	return (0);
}