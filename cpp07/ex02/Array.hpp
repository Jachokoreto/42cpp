#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
template <class T>
class Array
{

  public:
	Array(void);
	Array(unsigned int n); // creates an array of n elements init by default, 0
	Array(Array const &src);
	~Array();

	Array &operator=(Array const &rhs);
	T &operator[](unsigned long index);
	unsigned long size(void) const;

  private:
	T *_elements;
	unsigned long _size;
};

#include "Array.tpp"

#endif /* *********************************************************** ARRAY_H */