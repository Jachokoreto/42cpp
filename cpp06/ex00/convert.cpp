#include "convert.hpp"
#include "stdlib.h"
#include <climits>
#include <limits.h>
#include <limits>

void convertChar(std::string s, t_vars &v)
{
	v.c = s[0];
	v.i = v.c;
	v.f = v.c;
	v.d = v.c;
}

void convertInt(std::string s, t_vars &v)
{
	v.i = atof(s.c_str());
	v.c = static_cast<char>(v.i);
	v.f = v.i;
	v.d = v.i;
}

void convertFloat(std::string s, t_vars &v)
{
	v.f = atof(s.c_str());
	v.c = static_cast<char>(v.f);
	v.i = static_cast<int>(v.f);
	v.d = v.f;
}

void convertDouble(std::string s, t_vars &v)
{
	v.d = atof(s.c_str());
	v.c = static_cast<char>(v.d);
	v.i = static_cast<int>(v.d);
	v.f = static_cast<float>(v.d);
}

void printResults(t_vars &v)
{
	if (isprint(v.c) != 0 && v.d < CHAR_MAX && v.d > CHAR_MIN)
		std::cout << "char : '" << v.c << "'" << std::endl; // show message if not displayable 
	else if (v.d > CHAR_MAX || v.d < CHAR_MIN)
		std::cout << "char : impossible" << std::endl; 
	else
		std::cout << "char : non displayable" << std::endl; 
	if (v.d > INT_MAX || v.d < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else 
		std::cout << "int : " << v.i << std::endl;
	std::cout << "float : " << v.f << std::endl;
	std::cout << "double : " << v.d << std::endl;
}

void convert(e_type type, std::string s, t_vars &v)
{
	void (*func_arr[])(std::string,t_vars&) = {
		convertChar, convertInt, convertFloat, convertDouble
	};

	func_arr[type](s, v);
	printResults(v);
}

// If a conversion does not make any sense or overflows
