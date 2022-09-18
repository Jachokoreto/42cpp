#pragma once

template <class T>
Array<T>::Array(void)
{
	_elements = new T[1]();
	_size = 1;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	_elements = new T[n]();
	_size = n;
}

template <class T>
Array<T>::Array(Array const &src) : _elements(NULL)
{
	*this = src;
}

/**
 * I am trying to figure out a way to only free pointer when its been malloc,
 * but https://cboard.cprogramming.com/c-programming/74148-how-tell-if-pointer-has-had-memory-allocated-not.html
 * according to this, its best to initialized pointer with NULL. So when its not NULL,
 * means it has been allocated.
 **/
template <class T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	int len = rhs.size();
	if (_elements != NULL)
		delete this->_elements;
	this->_size = len;
	this->_elements = new T[len];
	while (--len >= 0)
		this->_elements[len] = rhs._elements[len];
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned long index)
{
	if (index < 0 || index >= _size)
		throw std::exception();
	return _elements[index];
}

template <class T>
unsigned long Array<T>::size(void) const
{
	return (_size);
}

template <class T>
Array<T>::~Array(void)
{
	delete[] _elements;
};