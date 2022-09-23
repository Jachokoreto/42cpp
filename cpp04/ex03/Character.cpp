#include "Character.hpp"
#include "jttool.hpp"

// Constructors
Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	std::cout << "\e[0;33mFields Constructor called of Character\e[0m" << std::endl;
}

Character::Character(const Character &copy) : _name(copy.getName())
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
Character &Character::operator=(const Character &assign)
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
	std::cout << "\e[0;33mCopy Assignment called of Character\e[0m" << std::endl;
	return *this;
}

// Getters / Setters
std::string const &Character::getName() const
{
	return _name;
}


// Stream operators
std::ostream &operator<<(std::ostream &stream, const Character &object)
{
	stream << "" << object.getName() << "" << std::endl;
	return stream;
}

// Methods
void Character::equip(AMateria *m)
{
	int idx;

	msg::info("Character -- Equip : " + this->_name);
	idx = 0;
	while (this->_inventory[idx] != NULL)
		idx++;
	if (idx != MAX_SLOT)
	{
		_inventory[idx] = m;
		std::cout << this->_name << " equiped " << m->getType() << " in slot " << idx << std::endl;
	}
	else
		std::cout << "Inventory is full for " << this->_name << std::endl;
}

void Character::unequip(int idx)
{
	msg::info("Character -- Unequip : " + this->_name);
	if (_inventory[idx] != NULL)
	{
		std::cout << this->_name << " unequiped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}

	else
		std::cout << this->_name << " have no Materia in slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	msg::info("Character -- Use : " + this->_name);
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << this->_name << " have no Materia in slot " << idx << std::endl;
}
