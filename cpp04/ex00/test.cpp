#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <cstdlib>

void test1(void)
{
	Animal *cat = new Cat();
	WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl << GRN "==== Test 1 required by subject ====" RESET << std::endl
			  << "- Created a Cat and WrongCat object" << std::endl;

	std::cout << "Cat makeSound(), "
			  << "implemented with virtual keyword in base Animal class"
			  << std::endl;
	cat->makeSound();

	std::cout << std::endl << "WrongCat makeSound(), "
			  << "implemented with NO virtual keyword in base WrongAnimal class"
			  << std::endl;
	wrongCat->makeSound();

	delete(cat);
	delete(wrongCat);

}

void test2(void)
{
	Animal a;
	Cat c;
	Animal *a2 = new Cat();

	std::cout << std::endl << GRN "==== Test 2 ====" RESET << std::endl;

	a = c;
	a.makeSound();
	c.makeSound();
	a2->makeSound();

	delete(a2);
}

int main(void)
{
	system("clear");
	test1();
	test2();

}