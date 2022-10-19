#include <iostream>
#include <cmath>
#include "Point.h"


const  int& Point::get_x() const
{
    return x;
}
const int& Point::get_y() const
{
    return y;
}
void Point::set_x(const int& _x)
{
    x = _x;
}
void Point::set_y(const int& _y)
{
    y = _y;
}
double Point::distance_to_start_coordinate() const
{
    return sqrt((x * x) + (y * y));
}
double Point::distance_to_point(const Point& point) const
{
    return sqrt(std::pow(point.get_x() - x, 2) + std::pow(point.get_y() - y, 2));
}
Point& Point::operator+= (const Point& point)
{
    x += point.get_x();
    y += point.get_y();
    return  *this;
}
Point& Point::operator+  (const Point& point) const
{
    Point res = *this;
    return  res += point;
}
Point& Point::operator-= (const Point& point)
{
    x -= point.get_x();
    y -= point.get_y();
    return  *this;
}
Point& Point::operator-  (const Point& point) const
{
    Point res = *this;
    return  res -= point;
}
bool Point::operator==(const Point& point) const
{
    return x == point.get_x()
        && y == point.get_y();
}
bool Point::operator!=(const Point& point) const
{
    return !(*this == point);
}
std::ostream&  operator<< (std::ostream& stream, const Point& point)
{
    stream << "x: " << point.get_x() << ' ' << "y: " << point.get_y() << '\n';
    return stream;
}
std::istream& operator>> (std::istream& stream, Point& point)
{
    stream >> point.x >> point.y;
    return stream;
}
