#include "Rectangle.h"
#include <math.h>

using namespace std;

Rectangle::Rectangle(double l, double w)
{
    // TODO: Implement constructor
    // Hint: Initialize length and width
    length = l;
    width = w;
}

double Rectangle::getArea()
{
    // TODO: Implement area calculation
    // Hint: length * width
    return length * width;
}

double Rectangle::getPerimeter()
{
    // TODO: Implement perimeter calculation
    // Hint: 2 * (length + width)
    return 2 * (length + width);
}

double Rectangle::getDiagonal()
{
    // TODO: Implement diagonal calculation
    // Hint: Use sqrt() and the Pythagorean theorem
    return sqrt((length * length) + (width * width));
}
