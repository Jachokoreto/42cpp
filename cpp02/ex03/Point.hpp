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

	Fixed getX(void) const;
	Fixed getY(void) const;

  private:
	const Fixed _x;
	const Fixed _y;
};

#endif