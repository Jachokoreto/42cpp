#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j << std::endl;
	std::cout << i << std::endl;


	delete j;//should not create a leak
	delete i;
	return (0);
}