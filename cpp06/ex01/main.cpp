#include <string>
#include <iostream>
#include "serial.hpp"
#include <stdint.h>

uintptr_t serialize(Data *ptr)
{
	uintptr_t tmp = (uintptr_t)ptr;
	return (tmp);
}

Data *deserialize(uintptr_t raw)
{
	Data *ptr =(Data *)raw;
	return (ptr);
}

int main(void)
{

	Data *data = new Data();
	Data *tmp;
	uintptr_t ptr;

	data->a = 1;
	data->b = 10;
	data->c = 100;
	ptr = serialize(data);
	tmp = deserialize(ptr);

	std::cout << "data : " << data << std::endl;
	std::cout << data->a + data->b + data->c << std::endl;

	std::cout << "tmp : " << tmp << std::endl;
	std::cout << tmp->a + tmp->b + tmp->c << std::endl;

	delete(data);
	return (0);
}