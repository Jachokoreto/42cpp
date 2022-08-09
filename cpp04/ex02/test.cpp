#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#include <cstdlib>

void test1(void)
{
	std::cout << std::endl << GRN "==== Test 1 required by subject ====" << std::endl
			  << "- Create 100 Animal, half Cat and half Dog" RESET << std::endl;

	Animal *animals[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			animals[i] = new Dog();
		else 
			animals[i] = new Cat();	
	}

	for (int i = 0; i < 100; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 100; i++)
		delete(animals[i]);
}

void test2(void)
{
	std::cout << std::endl << GRN "==== Test 2 ====" << std::endl
			  << "- Class init test" RESET << std::endl;

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
	std::cout << std::endl << GRN "==== Test 3 ====" << std::endl
			  << "- Brain test" RESET << std::endl;

	Animal *a;
	Animal *b;
	Cat c;

	a = new Cat(c);
	b = new Dog();
	
	msg::info("Initial brain of a and b");
	std::cout << "a brain: " << ((Cat*)a)->getBrain() << std::endl;
	std::cout << "b brain: " << ((Cat*)b)->getBrain() << std::endl;
	
	*a = *b;
	msg::info("*a = *b, noticed the brain address is still the same, only data was copied");
	std::cout << "a brain: " << ((Cat*)a)->getBrain() << std::endl;
	std::cout << "b brain: " << ((Cat*)b)->getBrain() << std::endl;

	msg::info("c brain");
	std::cout << "c brain: " << c.getBrain() << std::endl;

	delete(a);
	delete(b);
}

void test4(void)
{
	std::cout << std::endl << GRN "==== Test 4 ====" << std::endl
			  << "- Copy tests" RESET << std::endl;

	Cat c1("Tuna is great");
	Cat c2("Salmon is the best");
	Dog d1("Fetch is the best");
	Dog d2("I love to run");

	msg::info("Initial Cats, display in c1 c2 order");
	c1.makeSound();
	c2.makeSound();

	c1 = c2;
	msg::info("c1 = c2 , display in c1 c2 order");
	c1.makeSound();
	c2.makeSound();

	c1.getBrain()->setIdeas("Mackeral please");
	msg::info("change c1's idea, display in c1 c2 order");
	c1.makeSound();
	c2.makeSound();

	msg::info("Initial Dogs, display in d`1 d2 order");
	d1.makeSound();
	d2.makeSound();

	d1 = d2;
	msg::info("d1 = d2 , display in d1 d2 order");
	d1.makeSound();
	d2.makeSound();

	d1.getBrain()->setIdeas("Moreee patsss");
	msg::info("change d1's idea, display in d1 d2 order");
	d1.makeSound();
	d2.makeSound();

}

int main(void)
{
	system("clear");
	test1(); // subject required test
	test2(); // class init test
	test3(); // brain test
	test4(); // copy test

}