#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
  public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &point);
	Point &operator=(const Point &point);
	~Point(void);

  private:
	const Fixed x;
	const Fixed y;
};

#endif