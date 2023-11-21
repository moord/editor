#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "line.h"

// Примитив прямоугольник
class Rectangle : public Line
{
public:
    constexpr static char shapeName[]{"RECTANGLE"};

    Rectangle(){};
    Rectangle( Point _start, Point _end ): Line(_start, _end){};

    static Rectangle * Create ();
    void Draw();
    bool IsBelong(Point coord);
    void Save (std::ostream& os);
protected:
};

#endif // RECTANGLE_H
