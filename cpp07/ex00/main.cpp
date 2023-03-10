#include <string>
#include <iostream>
#include "whatever.hpp"
#include "jttool.hpp"


int main(void)
{
	int a = 10;
	int b = 20;

	for (int i = 0; i < 3; i++)
	{
		msg::info("Before swapping");
		std::cout << "a = " << a << std::endl
				  << "b = " << b << std::endl;
		msg::info("After swapping...");
		swap(a, b);
		std::cout << "a = " << a << std::endl
				  << "b = " << b << std::endl;
	}

	msg::info("Min and Max");
	std::cout << min(a, b) << std::endl
			  << max(a, b) << std::endl;

	msg::info("Return second one when equal, func(a, b)");
	a = 10;
	b = 10;
	int &bTmp = min(a, b);
	std::cout << "ret\t: " << &bTmp << std::endl
			  << "b\t: " << &b << std::endl;

	msg::info("Test from PDF");
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}