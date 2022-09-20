#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>

class NoOccuranceException : public std::exception
{
  public:
	const char *what() const _NOEXCEPT
	{
		return "No occurance";
	}
};

template <class T>
typename T::iterator easyfind(T &container, int needle)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), needle);
	if (it != container.end())
	{
		return it;
	}
	else
		throw NoOccuranceException();
};

#endif /* *********************************************************** ARRAY_H */