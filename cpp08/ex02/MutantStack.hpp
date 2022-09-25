#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(MutantStack const &src);
	~MutantStack(){};
	MutantStack &operator=(MutantStack const &rhs);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void)
	{
		return this->c.begin();
	}

	iterator end(void)
	{
		return this->c.end();
	}
};

#endif /* *********************************************************** ARRAY_H */