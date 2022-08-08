#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <cstdlib>

void test1(void)
{
	std::cout << std::endl << GRN "==== Test 1 required by subject ====" RESET << std::endl
			  << "- Created a Cat and WrongCat object" << std::endl;

	Animal *cat = new Cat();
	WrongAnimal *wrongCat = new WrongCat();

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
	std::cout << std::endl << GRN "==== Test 2 ====" RESET << std::endl;

	Animal a;
	Cat c;
	Dog d;
	Animal *a2 = new Cat();

	std::cout << "a is initialized as Animal class, then copy assign c to it" << std::endl;
	a = c;
	std::cout << "a " << a << std::endl;

	std::cout << "then copy assign d to it" << std::endl;
	a = d;
	std::cout << "a " << a << std::endl;

	std::cout << "c is initialized as Cat class" << std::endl;
	std::cout << "c " << c << std::endl;
	
	std::cout << std::endl << "Although (a)'s type value is Dog, (a) is still Animal class, so it makes Animal sound" << std::endl;
	a.makeSound();

	std::cout << std::endl << "(c) is Cat class, so it makes Cat sound" << std::endl;
	c.makeSound();

	std::cout << std::endl << "(a2) is Animal class pointer pointing to a Cat class, so we can make it call Cat makeSound()" << std::endl;
	a2->makeSound();

	delete(a2);
}

void test3(void)
{
	std::cout << std::endl << GRN "==== Test 3 ====" RESET << std::endl;
	std::cout << "More test coming soon..." << std::endl;
}

int main(void)
{
	system("clear");
	test1();
	test2();
	test3();

}