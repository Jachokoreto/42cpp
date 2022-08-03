#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
public:
	Animal(void);
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &Animal);
	~Animal(void);
};

#endif