#include <string>
#include <iostream>
#include "serial.hpp"
#include <stdint.h>

uintptr_t serialize(Data *ptr)
{
	uintptr_t tmp = reinterpret_cast<uintptr_t>(ptr);
	return (tmp);
}

Data *deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

int main(void)
{

	Data data;
	Data *tmp;
	uintptr_t ptr;

	data.a = 1;
	data.b = 10;
	data.c = 100;
	ptr = serialize(&data);
	tmp = deserialize(ptr);

	std::cout << "ptr :\t" << ptr << std::endl;

	std::cout << "data :\t" << &data << std::endl;
	std::cout << data.a + data.b + data.c << std::endl;

	std::cout << "tmp :\t" << tmp << std::endl;
	std::cout << tmp->a + tmp->b + tmp->c << std::endl;



	return (0);
}