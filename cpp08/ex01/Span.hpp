#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>

class Span
{
  public:
	Span(unsigned int n);
	Span(const Span &rhs);
	~Span(void);

	Span &operator=(const Span &rhs);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
	void addNumber(size_t n, int val);
	int shortestSpan(void);
	int longestSpan(void);
	void display(void);

	class NoSpanException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

	class ExceedLimitException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

  private:
	unsigned int _maxNum;
	std::vector<int> _element;
};

#endif /* *********************************************************** ARRAY_H */