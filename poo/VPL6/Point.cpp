#include <iostream>

#include "Point.h"

std::ostream & operator << (std::ostream &out, const Point &p) {
  return out << "(" << p.getX() << ", " << p.getY() << ")";
}

std::istream & operator >> (std::istream &in,  Point &p) {
  in >> p.x >> p.y; // pode fazer isso? eles sao privados
                    // se der pau usa o construtor
  return in;
}

Point Point::operator + (const Point &p) {
  Point ans;

  ans.x = this->getX() + p.getX();
  ans.y = this->getY() + p.getY();

  return ans;
}

Point& Point::operator += (const Point &p) {
  this->x = this->getX() + p.getX();
  this->y = this->getY() + p.getY();

  return *this;
}