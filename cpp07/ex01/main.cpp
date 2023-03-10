#include <string>
#include <iostream>
#include "iter.hpp"
#include "jttool.hpp"



int main(void)
{
	int num[] = {0, 1, 2, 3, 4, 5};
	char c[] = {'a', 'b', 'c', 'd'};
	std::string str[] = {"str1", "str2", "str3"};

	iter(num, 6,  read);
	iter(c, 4,  read);
	iter(str, 3, read);
	return 0;

}

