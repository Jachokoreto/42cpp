#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <stdlib.h>
#include "jttool.hpp"

void test1(void)
{
	msg::annouceTest("Test 1", "test given by main");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void test2(void)
{
	msg::annouceTest("Test 2", "to test use unavailable index");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *cloud = new Character("Cloud");
	ICharacter *tifa = new Character("Tifa");
	ICharacter *blob = new Character("Blob");

	cloud->equip(src->createMateria("ice"));
	cloud->equip(src->createMateria("cure"));

	tifa->equip(src->createMateria("ice"));
	tifa->equip(src->createMateria("cure"));

	cloud->use(0, *blob);
	cloud->use(1, *blob);
	cloud->use(2, *blob);

	tifa->use(0, *blob);
	tifa->use(1, *blob);
	tifa->use(2, *blob);

	delete src;
	delete cloud;
	delete tifa;

}

void test3(void)
{
	msg::annouceTest("Test 2", "to test equip and unequip");
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter *cloud = new Character("Cloud");

	cloud->unequip(0);

	AMateria *tmp = src->createMateria("ice");
	cloud->equip(tmp);

	cloud->unequip(0);

	delete src;
	delete cloud;
	delete tmp;

}

int main()
{
	test1();
	test2();
	test3();
	// system("leaks finalFantasy"); 
	return 0;
}