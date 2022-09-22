#include "Character.hpp"

// Constructors
Character::Character(std::string _name): _name(_name)
{
	for (int i = 0; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	std::cout << "\e[0;33mFields Constructor called of Character\e[0m" << std::endl;
}

Character::Character(const Character &copy): _name(copy.getName())
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Character\e[0m" << std::endl;
}


// Destructor
Character::~Character()
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "\e[0;31mDestructor called of Character\e[0m" << std::endl;
}


// Operators
Character & Character::operator=(const Character &assign)
{
	if (&assign != this)
	{
		this->_name = assign.getName();
		for (int i = 0; i < MAX_SLOT; i++)
		{
			if (this->_inventory[i] != NULL)
				delete _inventory[i];
			if (assign._inventory[i] != NULL)
				this->_inventory[i] = assign._inventory[i]->clone();
		}
	}
	return *this;
}


// Getters / Setters
std::string &Character::getName() const
{
	return _name;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Character &object)
{
	stream << "" << object.getName() << "" << std::endl;
	return stream;
}


// Methods
void Character::equip(AMateria *m)
{
	int idx;

	idx = 0;
	while (this->_inventory[idx])
		idx++;
	if (idx != MAX_SLOT)
		_inventory[idx] = m;
	else
		std::cout << "Inventory is full for " << this->_name << std::endl;
}

void Character::unequip(int idx)
{
	if (_inventory[idx] != NULL)
		_inventory[idx] = NULL;
	else
		std::cout << this->_name << " have no Materia in slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << this->_name << " have no Materia in slot " << idx << std::endl;
}
