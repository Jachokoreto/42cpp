#include "Span.hpp"
#include <algorithm>

// Constructors
Span::Span(unsigned int n): _maxNum(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}


// Destructor
Span::~Span()
{
}


// Operators
Span & Span::operator=(const Span &assign)
{
	this->_element = assign._element;
	return *this;
}

void Span::addNumber(int n)
{
	if (_element.size() < _maxNum)
		_element.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	std::vector<int>::iterator it = first;

	while (it != last)
	{
		_element.push_back(*it);
		it++;
	}
}

void Span::addNumber(size_t n, int val)
{
	for (int i = 0; i < n; i++)
	{
		_element.push_back(val);
	}
}


int Span::shortestSpan(void)
{
	if (_element.size() < 2)
		throw NoSpanException();

	int smallest;
	std::vector<int> sorted(_element);
	std::vector<int>::iterator it;

	smallest = UINT32_MAX;
	sort(sorted.begin(), sorted.end());
	
	while (it + 1 != sorted.end())
	{
		if ((*it + 1) - *it < smallest)
			smallest = (*it + 1) - *it;
		it++;
	}
	return (smallest);
}

int Span::longestSpan(void)
{
	if (_element.size() < 2)
		throw NoSpanException();

	std::vector<int>::iterator first = _element.begin();
	std::vector<int>::iterator last = _element.end();

	return (*std::max_element(first, last) - *std::min_element(first, last));
}

const char *Span::NoSpanException::what() const throw()
{
	return ("No span found");
}

