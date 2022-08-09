#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* j = new Dog();
	// const Animal i; // this is not allowed
	Cat c;

	std::cout << j << std::endl;
	std::cout << c << std::endl;

	delete j;//should not create a leak
	return (0);
}