#pragma once
#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    const int& get_x() const;
    const int& get_y() const;
    void set_x(const int& _x);
    void set_y(const int& _y);
    double distance_to_start_coordinate() const;
    double distance_to_point(const Point& point) const;
    Point& operator+= (const Point& point);
    Point& operator+  (const Point& point) const;
    Point& operator-= (const Point& point);
    Point& operator-  (const Point& point) const;
    bool operator== (const Point& point) const;
    bool operator!= (const Point& point) const;
    friend std::ostream& operator<< (std::ostream& stream, const Point& point);
    friend std::istream& operator>> (std::istream& stream, Point& point);
};