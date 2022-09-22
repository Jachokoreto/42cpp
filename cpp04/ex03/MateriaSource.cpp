#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_SLOT; i++)
		_storage[i] = NULL;
	std::cout << "\e[0;33mDefault Constructor called of MateriaSource\e[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of MateriaSource\e[0m" << std::endl;
}


// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (_storage[i] != NULL)
			delete _storage[i];
	}
	std::cout << "\e[0;31mDestructor called of MateriaSource\e[0m" << std::endl;
}


// Operators
MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < MAX_SLOT; i++)
		{
			if (this->_storage[i] != NULL)
				delete(_storage[i]);
			if (assign._storage[i] != NULL)
				this->_storage[i] = assign._storage[i]->clone();
		}
	}
	return *this;
}


// Methods
void MateriaSource::learnMateria(AMateria *learn)
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (_storage[i] == NULL)
			_storage[i] = learn->clone();
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i;

	i = 0;
	while (_storage[i] != NULL)
	{
		if (_storage[i]->getType() == type)
			return (_storage[i]->clone());
	}
	std::cout << "Can't find " << type << std::endl;
}