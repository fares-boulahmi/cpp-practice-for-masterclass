#ifndef Rectangle_H
#define Rectangle_H

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);
    double getArea();
    double getPerimeter();
    double getDiagonal();
};

#endif