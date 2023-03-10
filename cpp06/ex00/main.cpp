#include "convert.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cctype>

// inf = infinity, nan = not a number
int	forFun(std::string &input)
{
	std::string tmp;

	if (input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
		tmp = "inf";
	else if (input == "nan" || input == "nanf")
		tmp = "nan";
	if (tmp.empty() == 0)
	{
		std::cout << "char : impossible" << std::endl
				  << "int : impossible" << std::endl
				  << "float : " << tmp << "f" << std::endl
				  << "double : " << tmp << std::endl;
		return (1);
	}
	return (0);
}

// This literal must belong to one of the following a scalar types:
// char, int, float or double.
e_type detectType(std::string input)
{
	int	decimal;
	int	strLen;
	char	c;

	strLen = input.length();
	if (strLen == 1 && isdigit(input[0]) == false)
		return CHAR;
	decimal = 0;
	for (int i = 0; i < strLen; i++)
	{
		c = input[i];
		if (i == 0 && (c == '-' || c == '+'))
			continue;
		if (isdigit(c) == true)
			continue;
		if (c == '.' && decimal == 0 && isdigit(input[i + 1]) == true)
			decimal = 1;
		else if (c == 'f' && i == strLen - 1 && decimal == 1)
			return FLOAT;
		else
			return INVALID;
	}
	if (decimal == 0)
		return INT;
	else
		return DOUBLE;
}

int main( int argc, char **argv)
{
	std::string	types[] = {"CHAR", "INT", "FLOAT", "DOUBLE", "INVALID"};
	std::string	input;
	int			i;
	t_vars		vars;
	e_type		oriType;

	if (argc < 2)
		return (1);
	i = 0;
	while (++i < argc)
	{
		input = argv[i];
		if (forFun(input) == 1)
			continue;
		oriType = detectType(input);
		if (oriType == INVALID)
		{
			msg::info("Invalid");
			continue;
		}
		msg::info("Converting " + input + ", " + types[oriType]);
		convert(oriType, input, vars);
	}
}