#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>

class Span
{
  public:
	Span(unsigned int n);
	Span(const Span &rhs);
	~Span(void);

	Span &operator=(const Span &rhs);

	void addNumber(int n);
	int shortestSpan(void);
	int longestSpan(void);

  private:
	unsigned int _maxNum;
};

#endif /* *********************************************************** ARRAY_H */